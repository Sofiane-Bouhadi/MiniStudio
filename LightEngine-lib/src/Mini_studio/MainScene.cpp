#include "MainScene.h"
#include "Player.h"
#include "Level.h"
#include "Boss.h"

#include "AABBCollider.h"

#include "Utils.h"
#include "Debug.h"

#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>

void MainScene::OnInitialize() 
{
	srand(time(NULL));

	//Player
	m_Player = CreateRectangle<Player>(155, 225, sf::Color::Green, new AABBCollider(155, 225));
	m_Player->SetPosition(0, 600);
	m_Player->SetSpeed(m_Player->GetMinSpeed());
	m_Player->SetRigidBody(true);
	m_Player->SetGravityStrength(3000.f);
	m_Player->SetJumpStrength(1200);

	//Platform
	Entity* entity = CreateRectangle<Entity>(1280, 100, sf::Color::White, new AABBCollider(1280, 100));
	entity->SetStatic(true);
	entity->SetRigidBody(true);
	entity->SetPosition(0, 720);

	Boss* boss = CreateSprite<Boss>(558, 441, "../../../res/Sprites/Boss/Boss_Idle.png", new AABBCollider(558, 441));
	boss->SetPosition(0, 0);
	boss->SetRigidBody(false);
	boss->SetStatic(true);

	GameManager::Get()->GetCamera()->SetFollowingEntity(m_Player);
	GameManager::Get()->GetCamera()->Zoom(2.f);

	{
		///ENEMIES
		{
			tilePath[(int)ObjectType::Enemy1] = { "../../../res/Sprites/Enemies/Enemy1.png", false };
			tilePath[(int)ObjectType::Enemy2] = { "../../../res/Sprites/Enemies/Enemy2.png", false };
			tilePath[(int)ObjectType::Enemy3] = { "../../../res/Sprites/Enemies/Enemy2.png", true };
			tilePath[(int)ObjectType::Enemy4] = { "../../../res/Sprites/Enemies/Enemy2.png", true };
			tilePath[(int)ObjectType::Boss] = { "../../../res/Sprites/Enemies/Boss.png", true };
		}

		///CEILINGS
		{
			//Jazz
			{
				tilePath[(int)ObjectType::JazzCeiling1] = { "../../../res/Tiles/Jazz_Ceiling1.png", true };
				tilePath[(int)ObjectType::JazzCeiling2] = { "../../../res/Tiles/Jazz_Ceiling2.png", true };
			}
			//Metal
			{
				tilePath[(int)ObjectType::MetalCeiling1] = { "../../../res/Tiles/Metal_Ceiling1.png", true };
				tilePath[(int)ObjectType::MetalCeiling2] = { "../../../res/Tiles/Metal_Ceiling2.png", true };
			}
		}

		///WALLS
		{
			//Jazz
			{
				tilePath[(int)ObjectType::JazzWall1] = { "../../../res/Tiles/Jazz_Wall1.png", true };
				tilePath[(int)ObjectType::JazzWall2] = { "../../../res/Tiles/Jazz_Wall2.png", true };
			}
			//Hub
			{
				tilePath[(int)ObjectType::HubWall1] = { "../../../res/Tiles/Hub_Wall1.png", true };
				tilePath[(int)ObjectType::HubWall2] = { "../../../res/Tiles/Hub_Wall2.png", true };
			}
			//Metal
			{
				tilePath[(int)ObjectType::MetalWall1] = { "../../../res/Tiles/Metal_Wall1.png", true };
				tilePath[(int)ObjectType::MetalWall2] = { "../../../res/Tiles/Metal_Wall2.png", true };
			}
		}

		///GROUNDS
		{
			//Jazz
			{
				tilePath[(int)ObjectType::JazzGround1] = { "../../../res/Tiles/Jazz_Ground1.png", true };
				tilePath[(int)ObjectType::JazzGround2] = { "../../../res/Tiles/Jazz_Ground2.png", true };
				tilePath[(int)ObjectType::JazzGroundCorner] = { "../../../res/Tiles/Jazz_Ground2.png", true };
				tilePath[(int)ObjectType::JazzToHubGround1] = { "../../../res/Tiles/Jazz_Ground2.png", true };
				tilePath[(int)ObjectType::JazzToHubGround2] = { "../../../res/Tiles/Jazz_Ground2.png", true };
			}
			//Hub
			{
				tilePath[(int)ObjectType::HubGround] = { "../../../res/Tiles/Hub_Ground.png", true };
			}
			//Metal
			{
				tilePath[(int)ObjectType::MetalWall1] = { "../../../res/Tiles/Metal_Ground1.png", true };
				tilePath[(int)ObjectType::MetalWall2] = { "../../../res/Tiles/Metal_Ground2.png", true };
			}
		}

		///PLATFORMS
		{
			//Jazz
			{
				tilePath[(int)ObjectType::JazzUpperLeftPlatform] = { "../../../res/Tiles/Jazz_Upper_Left_Platform.png", true };
				tilePath[(int)ObjectType::JazzUpperMiddlePlatform] = { "../../../res/Tiles/Jazz_Upper_Middle_Platform.png", true };
				tilePath[(int)ObjectType::JazzUpperRightPlatform] = { "../../../res/Tiles/Jazz_Upper_Right_Platform.png", true };
				tilePath[(int)ObjectType::JazzBottomLeftPlatform] = { "../../../res/Tiles/Jazz_Bottom_Left_Platform.png", true };
				tilePath[(int)ObjectType::JazzBottomMiddlePlatform] = { "../../../res/Tiles/Jazz_Bottom_Middle_Platform.png", true };
				tilePath[(int)ObjectType::JazzBottomRightPlatform] = { "../../../res/Tiles/Jazz_Bottom_Right_Platform.png", true };
			}

			//Metal
			{
				tilePath[(int)ObjectType::MetalLeftPlatform] = { "../../../res/Tiles/Metal_Left_Platform.png", true };
				tilePath[(int)ObjectType::MetalMiddlePlatform1] = { "../../../res/Tiles/Metal_Middle_Platform1.png", true };
				tilePath[(int)ObjectType::MetalMiddlePlatform2] = { "../../../res/Tiles/Metal_Middle_Platform2.png", true };
				tilePath[(int)ObjectType::MetalRightPlatform] = { "../../../res/Tiles/Metal_Right_Platform.png", true };
			}
		}
	}

	//m_Level = new Level("../../../res/Levels/levelFull.txt", this);
}

void MainScene::OnEvent(const sf::Event& event)
{
	bool MoveRight = false;
	bool MoveLeft = false;
	bool jump = false;
	bool base_attack = false;
	bool shoot = false;
	

	if (event.type == sf::Event::KeyPressed )
	{

		if (event.key.code == sf::Keyboard::Space && m_Player->GetNbJump() > 0)
		{
			std::cout << "espace est press�" << std::endl;
			jump = true;
			m_Player->DecreaseJump();
			
		}
	}

	if (event.type == sf::Event::MouseButtonPressed) 
	{
		if (event.mouseButton.button == sf::Mouse::Button::Left)
		{
			std::cout << "clic gauche est appuy�" << std::endl;
			base_attack = true;
		}
		if (event.mouseButton.button == sf::Mouse::Button::Right && m_Player->GetShootCD() <= 0.f)
		{
			std::cout << "clic droit est appuy�" << std::endl;
			shoot = true;
		}
	}

	if (event.type == sf::Event::JoystickMoved)
	{
		sf::Joystick::Axis axis = event.joystickMove.axis;

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
			std::cout << "A est appuy�" << std::endl;
			jump = true;
			m_Player->DecreaseJump();
		}

		if (sf::Joystick::isButtonPressed(0, 2))
		{
			std::cout << "X est appuy�" << std::endl;
			base_attack = true;
		}
		
		if (sf::Joystick::isButtonPressed(0, 3) && m_Player->GetShootCD() <= 0.f)
		{
			std::cout << "Y est appuy�" << std::endl;
			 shoot = true;
		}
	}

	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::D)
		{
			std::cout << "d est relach�" << std::endl;
			MoveRight = false;
			m_Player->SetSpeed(0);
			m_Player->SetDirection(0, m_Player->GetPosition().y, 0);
		}
		
		if (event.key.code == sf::Keyboard::Q)
		{
			std::cout << "q est relach�" << std::endl;
			MoveLeft = false;
			m_Player->SetSpeed(0);
			m_Player->SetDirection(0, m_Player->GetPosition().y, 0);
		}

		if (event.key.code == sf::Keyboard::Space )
		{
			std::cout << "espace est relach�" << std::endl;
			m_Player->SetSpeed(0);
			jump = false;
		}
	}
	
	if (event.type == sf::Event::MouseButtonReleased) 
	{
		if (event.mouseButton.button == sf::Mouse::Button::Left )
		{
			base_attack = false;
		}
		if (event.mouseButton.button == sf::Mouse::Button::Right)
		{
			shoot = false;
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
			jump = false;
		}

		if (sf::Event::JoystickButtonReleased == 3)
		{
			shoot = false;

		}
	}

	if (jump) 
	{
		m_Player->Jump();
	}
	if (base_attack) 
	{
		m_Player->BaseAttack();
	}
	if (shoot) 
	{
		m_Player->PlayerShoot();
	}
}

void MainScene::OnUpdate()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		std::cout << "d est press�" << std::endl;
		m_Player->MoveRight(GetDeltaTime());
		/*if (m_Player->GetAttack() == false)*/
		
			m_Player->SetRight();
			m_Player->UnsetLeft();
		

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		std::cout << "q est press�" << std::endl;
		m_Player->MoveLeft(GetDeltaTime());
		/*if (m_Player->GetAttack() == false)*/
		
			m_Player->SetLeft();
			m_Player->UnsetRight();
		

	}
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 10)
	{
		std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << std::endl;
		m_Player->MoveRight(GetDeltaTime());

		/*if (m_Player->GetAttack() == true)*/

		m_Player->SetRight();
		m_Player->UnsetLeft();

	}
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -10)
	{
		std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << std::endl;
		m_Player->MoveLeft(GetDeltaTime());

		/*if (m_Player->GetAttack() == true)*/

		m_Player->SetLeft();
		m_Player->UnsetRight();
	}
}

void MainScene::Spawn(ObjectType objectType, float levelX, float levelY)
{
	Entity* pEntity = CreateSprite<Entity>(128.f, 128.f, tilePath[(int)objectType].path, nullptr);
	pEntity->SetStatic(tilePath[(int)objectType].isStatic);

	if (pEntity != nullptr)
	{
		pEntity->SetRigidBody(true);
		pEntity->SetPosition(levelX, levelY, 0.f, 0.f);
	}
}

void MainScene::SpawnCollider(float x, float y, float width, float height)
{
	Entity* pEntity = CreateRectangle<Entity>(width, height, sf::Color::Transparent, new AABBCollider(width, height));
	pEntity->SetPosition(x, y, 0.f, 0.f);
	pEntity->SetRigidBody(true);
	pEntity->SetStatic(true);
}
