#include "MainScene.h"
#include "Player.h"
#include "Level.h"
#include "Boss.h"

#include "AABBCollider.h"

#include "Utils.h"
#include "Debug.h"
#include <iostream>
#include "AABBCollider.h"
#include <SFML/Graphics/RectangleShape.hpp>

void MainScene::Spawn(ObjectType objectType, float levelX, float levelY){}
void MainScene::SpawnCollider(float x, float y, float width, float height){}
void MainScene::OnInitialize() 
{
	srand(time(NULL));

	//Player
	m_Player = CreateRectangle<Player>(155, 225, sf::Color::Green, new AABBCollider(155, 225));
	m_Player->SetPosition(0, 600);
	m_Player->SetSpeed(m_Player->GetMinSpeed());
	m_Player->SetRigidBody(true);
	m_Player->SetGravityStrength(5000.f);
	m_Player->SetJumpStrength(1800);

	//Platform
	Entity* entity = CreateRectangle<Entity>(3000, 100, sf::Color::White, new AABBCollider(3000, 100));
	entity->SetStatic(true);
	entity->SetRigidBody(true);
	entity->SetPosition(0, 720);

	//Boss
	Boss* boss = CreateSprite<Boss>(600, 600, "../../../res/Sprites/Boss/Boss_Idle.png", new AABBCollider(600, 600));
	boss->SetPosition(0, 0);
	boss->SetRigidBody(false);
	boss->SetStatic(true);

	enemy1= CreateSprite<enemies>(128, 128,R"(..\..\..\asset_by_tech\sniper.png)", new AABBCollider(128, 128));
	enemy1->SetRigidBody(true);
	enemy1->SetPosition(100, 100);
	enemy1->init(enemy1, m_Player);
	enemy1->SetGravityStrength(0);

	enemy2 = CreateSprite<enemies>(128, 128, R"(..\..\..\asset_by_tech\stamp.png)", new AABBCollider(128, 128));
	enemy2->SetRigidBody(true);
	enemy2->SetPosition(200, 300);
	enemy2->init(enemy2, m_Player);
	enemy2->SetGravityStrength(0);

	enemy3 = CreateSprite<enemies>(128, 128, R"(..\..\..\asset_by_tech\stamp.png)", new AABBCollider(128, 128));
	enemy3->SetRigidBody(true);
	enemy3->SetPosition(350, 300);
	enemy3->init(enemy3, m_Player);
	enemy3->SetGravityStrength(0);

	enemy4 = CreateSprite<enemies>(128, 128, R"(..\..\..\asset_by_tech\sniper.png)", new AABBCollider(128, 128));
	enemy4->SetRigidBody(true);
	enemy4->SetPosition(400, 100);
	enemy4->init(enemy4, m_Player);
	enemy4->SetGravityStrength(0);
}

void MainScene::OnEvent(const sf::Event& event)
{
	

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
	fall_attack = false;
	smart_attack = false;

	if (event.type == sf::Event::KeyPressed )
	{

		if (event.key.code == sf::Keyboard::Space && m_Player->GetNbJump() > 0)
		{
			//std::cout << "espace est pressé" << std::endl;
			jump = true;
			m_Player->DecreaseJump();
			
		}
	}

	if (event.type == sf::Event::MouseButtonPressed) 
	{
		if (event.mouseButton.button == sf::Mouse::Button::Right)
		{
			//std::cout << "clic droit est appuyé" << std::endl;
			base_attack = true;
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
			//std::cout << "A est appuyé" << std::endl;
			jump = true;
			m_Player->DecreaseJump();
		}

		if (sf::Joystick::isButtonPressed(0, 2))
		{
			//std::cout << "X est appuyé" << std::endl;
			base_attack = true;
		}
	}

	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::D)
		{
			//std::cout << "d est relaché" << std::endl;
			MoveRight = false;
			m_Player->SetSpeed(0);
			m_Player->SetDirection(0, m_Player->GetPosition().y, 0);
		}
		
		if (event.key.code == sf::Keyboard::Q)
		{
			//std::cout << "q est relaché" << std::endl;
			MoveLeft = false;
			m_Player->SetSpeed(0);
			m_Player->SetDirection(0, m_Player->GetPosition().y, 0);
		}

		if (event.key.code == sf::Keyboard::Space )
		{
			//std::cout << "espace est relaché" << std::endl;
			m_Player->SetSpeed(0);
			jump = false;
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
			jump = false;}
	}
	if (jump) {
		m_Player->Jump();
	}

	if (base_attack){
		m_Player->BaseAttack();
	}
}

void MainScene::OnUpdate() 
{
	enemy1->OnCollision(m_Player, Entity::CollidingSide::Other);
	enemy2->OnCollision(m_Player, Entity::CollidingSide::Other);
	enemy3->OnCollision(m_Player, Entity::CollidingSide::Other);
	enemy4->OnCollision(m_Player, Entity::CollidingSide::Other);

	if (enemy1->telemetrie() <= 800 && enemy1 != nullptr) {
		//std::cout << "detected" << std::endl;
		fall_attack = true;
		smart_attack = true;
	}
	else {
		//std::cout << "lost" << std::endl;
		fall_attack = false;
		smart_attack = false;
	}
	//std::cout << enemy1->telemetrie() << std::endl;
	if (fall_attack) {
		ia->liveFall(enemy2);
		ia->liveFall(enemy3);
	}
	if (smart_attack) {
		ia->liveShot(enemy1);
		ia->liveShot(enemy4);
	}
	
	//enemy1->moveingInLigne(100,500);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
	{
		//std::cout << "d est pressé" << std::endl;
		m_Player->MoveRight(GetDeltaTime());
		if (m_Player->GetAttack() == false) 
		{
			m_Player->SetRight();
		}
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		//std::cout << "q est pressé" << std::endl;
		m_Player->MoveLeft(GetDeltaTime());
		if (m_Player->GetAttack() == false) 
		{
			m_Player->SetLeft();
		}
		
	}

	

	if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 10) 
	{
		//std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << std::endl;
		m_Player->MoveRight(GetDeltaTime());

		/*if (m_Player->GetAttack() == true)*/
		
			m_Player->SetRight();
			m_Player->UnsetLeft();
		
	}
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -10)
	{
		//std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << std::endl;
		m_Player->MoveLeft(GetDeltaTime());
		
		/*if (m_Player->GetAttack() == true)*/
		
			m_Player->SetLeft();
			m_Player->UnsetRight();

	}


	/*std::cout << "x:" << m_Player->GetPosition().x << " y: " << m_Player->GetPosition().y << " speed : " << m_Player->GetSpeed() <<  std::endl;*/
	
}
