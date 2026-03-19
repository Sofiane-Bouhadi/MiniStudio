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
	m_Player = CreateRectangle<Player>(155, 225, sf::Color::Green, new AABBCollider(155, 225));
	m_Player->SetPosition(1000, 300);
	m_Player->SetSpeed(m_Player->GetMinSpeed());
	m_Player->SetRigidBody(true);
	m_Player->SetGravityStrength(1200.f);
	m_Player->SetJumpStrength(750);

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
				tilePath[(int)ObjectType::JazzCeillingP] = { "../../../res/Tiles/Jazz_Ceiling1.png", true };
				tilePath[(int)ObjectType::JazzCeillingY] = { "../../../res/Tiles/Jazz_Ceiling2.png", true };
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
				tilePath[(int)ObjectType::JazzWallBLY] = { "../../../res/Tiles/Jazz_Wall1.png", true };
				tilePath[(int)ObjectType::JazzWallBRY] = { "../../../res/Tiles/Jazz_Wall2.png", true };
			}
			//Hub
			{
				tilePath[(int)ObjectType::HubWall1] = { "../../../res/Tiles/Hub_Wall1.png", true };
				tilePath[(int)ObjectType::HubWall2] = { "../../../res/Tiles/Hub_Wall2.png", true };
			}
			//Metal
			{
				tilePath[(int)ObjectType::MetalWallBL] = { "../../../res/Tiles/Metal_Wall1.png", true };
				tilePath[(int)ObjectType::MetalWallBR] = { "../../../res/Tiles/Metal_Wall2.png", true };
			}
		}

		///GROUNDS
		{
			//Jazz
			{
				tilePath[(int)ObjectType::JazzGroundY] = { "../../../res/Tiles/Jazz_Ground1.png", true };
				tilePath[(int)ObjectType::JazzGroundP] = { "../../../res/Tiles/Jazz_Ground2.png", true };
				tilePath[(int)ObjectType::JazzGroundCorner] = { "../../../res/Tiles/Jazz_Ground2.png", true };
				tilePath[(int)ObjectType::JazzToHubGround1] = { "../../../res/Tiles/Jazz_Ground2.png", true };
				tilePath[(int)ObjectType::JazzToHubGroundCorner] = { "../../../res/Tiles/Jazz_Ground2.png", true };
			}
			//Hub
			{
				tilePath[(int)ObjectType::HubGround] = { "../../../res/Tiles/Hub_Ground.png", true };
			}
			//Metal
			{
				tilePath[(int)ObjectType::MetalWallBL] = { "../../../res/Tiles/Metal_Ground1.png", true };
				tilePath[(int)ObjectType::MetalWallBR] = { "../../../res/Tiles/Metal_Ground2.png", true };
				tilePath[(int)ObjectType::MetalWall3] = { "../../../res/Tiles/Metal_Ground2.png", true };
				tilePath[(int)ObjectType::MetalWall4] = { "../../../res/Tiles/Metal_Ground2.png", true };
				tilePath[(int)ObjectType::MetalWall5] = { "../../../res/Tiles/Metal_Ground2.png", true };
			}
		}

		///PLATFORMS
		{
			//Jazz
			{
				tilePath[(int)ObjectType::JazzPlatform] = { "../../../res/Tiles/Jazz_Upper_Left_Platform.png", true };
				tilePath[(int)ObjectType::PlateformSide] = { "../../../res/Tiles/Jazz_Upper_Middle_Platform.png", true };
				tilePath[(int)ObjectType::PlateformIn] = { "../../../res/Tiles/Jazz_Upper_Right_Platform.png", true };
				tilePath[(int)ObjectType::BedPlaLeft] = { "../../../res/Tiles/Jazz_Bottom_Left_Platform.png", true };
				tilePath[(int)ObjectType::BedPlaMid] = { "../../../res/Tiles/Jazz_Bottom_Middle_Platform.png", true };
				tilePath[(int)ObjectType::BedPlaRight] = { "../../../res/Tiles/Jazz_Bottom_Right_Platform.png", true };
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

	m_Level = new Level("../../../res/Levels/levelFull.txt", this);
}

void MainScene::OnEvent(const sf::Event& event)
{
	bool MoveRight = false;
	bool MoveLeft = false;
	bool jump = false;
	bool base_attack = false;

	if (event.type == sf::Event::KeyPressed )
	{

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

	if (jump) 
	{
		m_Player->Jump();
	}
	if (base_attack) 
	{
		m_Player->BaseAttack();
	}
}

void MainScene::OnUpdate() 
{
	float AttackCD = m_Player->GetAttackCD();
	AttackCD -= GetDeltaTime();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
	{
		std::cout << "d est pressé" << std::endl;
		m_Player->MoveRight(GetDeltaTime());
		m_Player->SetRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		std::cout << "q est pressé" << std::endl;
		m_Player->MoveLeft(GetDeltaTime());
		m_Player->SetLeft();
	}
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 10)
	{
		std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << std::endl;
		m_Player->MoveRight(GetDeltaTime());
		if (m_Player->GetAttack() == false)
		{
			m_Player->SetRight();
		}
		if (m_Player->GetAttack() == true && AttackCD < 0)
		{
			m_Player->UnsetRight();
		}
	}
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < -10)
	{
		std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << std::endl;
		m_Player->MoveLeft(GetDeltaTime());
		if (m_Player->GetAttack() == false)
		{
			m_Player->SetLeft();
		}
		if (m_Player->GetAttack() == true && AttackCD < 0)
		{
			m_Player->UnsetLeft();
		}
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
