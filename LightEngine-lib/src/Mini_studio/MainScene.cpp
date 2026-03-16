#include "MainScene.h"
#include "Player.h"
#include "Level.h"

#include "AABBCollider.h"

#include "Utils.h"
#include "Debug.h"

#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>

void MainScene::OnInitialize() 
{
	//Player
	m_Player = CreateRectangle<Player>(155, 225, sf::Color::Green,new AABBCollider(155,225) );
	m_Player->SetPosition(2000, 700);
	m_Player->SetSpeed(m_Player->GetMinSpeed());
	m_Player->SetRigidBody(true);
	m_Player->SetGravityStrength(500.f);
	m_Player->SetJumpStrength(300);

	GameManager::Get()->GetCamera()->SetFollowingEntity(m_Player);
	GameManager::Get()->GetCamera()->Resize(sf::Vector2f(1280, 720));

	m_Level = new Level("../../../res/Levels/level.txt", this);
}

void MainScene::OnEvent(const sf::Event& event)
{
	
	bool MoveRight = false;
	bool MoveLeft = false;
	bool jump = false;
	bool base_attack = false;



	if (event.type == sf::Event::KeyPressed )
	{
		if (event.key.code == sf::Keyboard::D )
		{
			std::cout << "d est pressé" << std::endl;
			MoveRight = true;
			m_Player->NotLeft();
			m_Player->SetRight();
		}

		if (event.key.code == sf::Keyboard::Q )
		{
			std::cout << "q est pressé" << std::endl;
			MoveLeft = true;
			m_Player->NotRight();
			m_Player->SetLeft();
			
		}

		if (event.key.code == sf::Keyboard::Space && m_Player->GetNbJump() > 0)
		{
			std::cout << "espace est pressé" << std::endl;
			jump = true;
			m_Player->DecreaseJump();
			
		}

		
	}

	if (event.type == sf::Event::MouseButtonPressed) 
	{
		if (event.mouseButton.button == sf::Mouse::Button::Right)
		{
			std::cout << "clic droit est appuyé" << std::endl;
			base_attack = true;
		}
	}

	if (event.type == sf::Event::JoystickMoved)
	{

		sf::Joystick::Axis axis = event.joystickMove.axis;

		if (sf::Joystick::getAxisPosition(0,axis) > 10 && axis == sf::Joystick::X)
		{
			std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << std::endl;
			MoveRight = true;
			m_Player->NotLeft();
			m_Player->SetRight();
		}
		
		if (sf::Joystick::getAxisPosition(0, axis) < -10 && axis == sf::Joystick::X)
		{
			std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << std::endl;
			MoveLeft = true;
			m_Player->NotRight();
			m_Player->SetLeft();

		}

		if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < 10 && axis == sf::Joystick::X && -10 < sf::Joystick::getAxisPosition(0, sf::Joystick::X))
		{
			MoveRight = false;
			MoveLeft = false;
			m_Player->SetSpeed(0);
		}
		

	}

	if (event.type == sf::Event::JoystickButtonPressed)
	{
		if (sf::Joystick::isButtonPressed(0, 0) && m_Player->GetNbJump() > 0)
		{
			std::cout << "A est appuyé" << std::endl;
			jump = true;
			m_Player->DecreaseJump();
		}

		if (sf::Joystick::isButtonPressed(0, 2))
		{
			std::cout << "X est appuyé" << std::endl;
			base_attack = true;
		}
	}

	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::D)
		{
			std::cout << "d est relaché" << std::endl;
			MoveRight = false;
			m_Player->SetSpeed(0);
			m_Player->SetDirection(0, m_Player->GetPosition().y, 0);
		}
		
		if (event.mouseButton.button == sf::Keyboard::Q)
		{
			std::cout << "q est relaché" << std::endl;
			MoveLeft = false;
			m_Player->SetSpeed(0);
			m_Player->SetDirection(0, m_Player->GetPosition().y, 0);
		}

		if (event.mouseButton.button == sf::Keyboard::Space )
		{
			std::cout << "espace est relaché" << std::endl;
			m_Player->SetSpeed(0);
			jump == false;
		}

		
	}
	
	if (event.type == sf::Event::MouseButtonReleased) 
	{
		if (event.mouseButton.button == sf::Mouse::Button::Right )
		{
			base_attack = false;
		}
	}

	if (event.type == sf::Event::JoystickButtonReleased) 
	{

		if (sf::Event::JoystickButtonReleased == 2)
		{
			base_attack = false;

		}

		if (sf::Event::JoystickButtonReleased == 0) 
		{
			m_Player->SetSpeed(0);
			jump == false;
		}
	}



	if (MoveRight) 
	{
		m_Player->MoveRight(GetDeltaTime());
	}
	if (MoveLeft) 
	{
		m_Player->MoveLeft(GetDeltaTime());
	}
	if (jump) 
	{
		m_Player->Jump();
	}
	if (base_attack) 
	{
		m_Player->BaseAttack();
		
	}
}

struct ColliderMergeCoords
{
	float xMin, xMax;
	float yMin, yMax;
};

void MainScene::Spawn(ObjectType objectType, float levelX, float levelY)
{
	Entity* pEntity = nullptr;

	std::list<ColliderMergeCoords>;

	switch (objectType)
	{
	case Enemy1:
		//mEnemies.push_back(CreateSprite<GravityEntity>(64.f, 64.f, "../../../res/Sprites/Enemies/Enemy1.png", new AABBCollider(64, 64)));
		//mEnemies.push_back(pEntity);
		break;
	case Enemy2:
		//pEntity = (CreateSprite<GravityEntity>(64.f, 64.f, "../../../res/Sprites/Enemies/Enemy2.png", new AABBCollider(64, 64)));
		//mEnemies.push_back(pEntity);
		break;
	case Enemy3:
		//pEntity = (CreateSprite<GravityEntity>(64.f, 64.f, "../../../res/Sprites/Enemies/Enemy3.png", new AABBCollider(64, 64)));
		//mEnemies.push_back(pEntity);
		break;
	case Enemy4:
		//pEntity = (CreateSprite<GravityEntity>(64.f, 64.f, "../../../res/Sprites/Enemies/Enemy4.png", new AABBCollider(64, 64)));
		//mEnemies.push_back(pEntity);
		break;
	case Platform:
		//pEntity = CreateSprite<Entity>(64.f, 64.f, "../../../res/Tiles/Platform.png", new AABBCollider(64, 64));
		//pEntity->SetStatic(true);
		break;
	case DestructiblePlatform:
		//pEntity = CreateSprite<Entity>(64.f, 64.f, "../../../res/Tiles/DestructiblePlatform.png", new AABBCollider(64, 64));
		//pEntity->SetStatic(true);
		break;
	case Wall:
		//pEntity = CreateSprite<Entity>(64.f, 64.f, "../../../res/Tiles/Wall.png", new AABBCollider(64, 64));
		//pEntity->SetStatic(true);
		break;
	case Ground:
		pEntity = CreateSprite<Entity>(124.f, 124.f, "../../../res/Tiles/Hub_Ground.png", new AABBCollider(124, 124));
		pEntity->SetStatic(true);
		break;
	}

	if (pEntity != nullptr)
	{
		pEntity->SetRigidBody(true);
		pEntity->SetPosition(levelX, levelY, 0.f, 0.5f);
	}
}

void MainScene::OnUpdate() 
{
}
