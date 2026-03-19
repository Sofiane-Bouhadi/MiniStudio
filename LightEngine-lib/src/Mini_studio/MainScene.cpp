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
	//Platform
	Entity* entity = CreateRectangle<Entity>(3000, 100, sf::Color::White, new AABBCollider(3000, 100));
	entity->SetStatic(true);
	entity->SetRigidBody(true);
	entity->SetPosition(0, 720);

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
				tilePath[(int)ObjectType::JazzCeillingP] = { "../../../res/Tiles/TILES_JAZZ/Plafond2.png", true };//
				tilePath[(int)ObjectType::JazzCeillingY] = { "../../../res/Tiles/TILES_JAZZ/Plafond1.png", true };//
			}
			//Metal
			{
				tilePath[(int)ObjectType::MetalCeiling1] = { "../../../res/Tiles/TILES_METAL/Plafond1.png", true };//
				tilePath[(int)ObjectType::MetalCeiling2] = { "../../../res/Tiles/TILES_METAL/Plafond1.png", true };//
			}
		}

		///WALLS
		{
			//Jazz
			{
				tilePath[(int)ObjectType::JazzWallBLY] = { "../../../res/Tiles/TILES_JAZZ/Mur1.png", true };//
				tilePath[(int)ObjectType::JazzWallBRY] = { "../../../res/Tiles/TILES_JAZZ/Mur2.png", true };//

				// TODO CHANGE PATH
				tilePath[(int)ObjectType::JazzWallBBicolore] = { "../../../res/Tiles/TILES_JAZZ/Mur4.png", true };//
				tilePath[(int)ObjectType::JazzWallBBlueOut] = { "../../../res/Tiles/TILES_JAZZ/Mur7.png", true };//
				tilePath[(int)ObjectType::JazzWallBLP] = { "../../../res/Tiles/TILES_JAZZ/Mur5.png", true };//
				tilePath[(int)ObjectType::JazzWallBRP] = { "../../../res/Tiles/TILES_JAZZ/Mur6.png", true };//
				tilePath[(int)ObjectType::JazzWallFill] = { "../../../res/Tiles/TILES_JAZZ/Mur8(remplissage).png", true };//
			}
			//Hub
			{
				tilePath[(int)ObjectType::HubWall1] = { "../../../res/Tiles/TILES_HUB/Mur2.png", true };//
				tilePath[(int)ObjectType::HubWall2] = { "../../../res/Tiles/TILES_HUB/Mur4.png", true };//
				// TODO CHANGE PATH
				tilePath[(int)ObjectType::HubCornerDL] = { "../../../res/Tiles/TILES_HUB/Mur1.png", true };//
				tilePath[(int)ObjectType::HubCornerDR] = { "../../../res/Tiles/TILES_HUB/Mur3.png", true };//
			}
			//Metal
			{
				tilePath[(int)ObjectType::MetalGround1] = { "../../../res/Tiles/TILES_METAL/Mur1.png", true };//
				tilePath[(int)ObjectType::MetalGround2] = { "../../../res/Tiles/TILES_METAL/Mur5.png", true };//
			}
		}

		///GROUNDS
		{
			//Jazz
			{
				// TODO CHANGE PATH
				tilePath[(int)ObjectType::JazzGroundY] = { "../../../res/Tiles/TILES_JAZZ/Sol1.png", true };//
				tilePath[(int)ObjectType::JazzGroundP] = { "../../../res/Tiles/TILES_JAZZ/Sol3.png", true };//
				tilePath[(int)ObjectType::JazzGroundCorner] = { "../../../res/Tiles/TILES_JAZZ/Sol2.png", true };//
				tilePath[(int)ObjectType::JazzToHubGround1] = { "../../../res/Tiles/TILES_JAZZ/Sol4.png", true };//
				tilePath[(int)ObjectType::JazzToHubGroundCorner] = { "../../../res/Tiles/TILES_JAZZ/Sol5.png", true };//
			}
			//Hub
			{
				tilePath[(int)ObjectType::HubGround] = { "../../../res/Tiles/TILES_HUB/Sol.png", true };//
				tilePath[(int)ObjectType::HubWallFill] = { "../../../res/Tiles/TILES_HUB/Mur5.png", true };//
			}
			//Metal
			{
				// TODO CHANGE PATH
				tilePath[(int)ObjectType::MetalWall3] = { "../../../res/Tiles/TILES_METAL/Mur4.png", true };//
				tilePath[(int)ObjectType::MetalWall4] = { "../../../res/Tiles/TILES_METAL/Mur2.png", true };//
				tilePath[(int)ObjectType::MetalWall5] = { "../../../res/Tiles/TILES_METAL/Mur3.png", true };//
			}
		}

		///PLATFORMS
		{
			//Jazz
			{
				// TODO CHANGE PATH
				tilePath[(int)ObjectType::JazzPlatform] = { "../../../res/Tiles/TILES_JAZZ/Plat1.png", true };//
				tilePath[(int)ObjectType::PlateformSide] = { "../../../res/Tiles/TILES_JAZZ/Plat2.png", true };//
				tilePath[(int)ObjectType::PlateformIn] = { "../../../res/Tiles/TILES_JAZZ/Mur9.png", true };//
				tilePath[(int)ObjectType::BedPlaLeft] = { "../../../res/Tiles/TILES_JAZZ/Plat10.png", true };//
				tilePath[(int)ObjectType::BedPlaMid] = { "../../../res/Tiles/TILES_JAZZ/Plat9.png", true };//
				tilePath[(int)ObjectType::BedPlaRight] = { "../../../res/Tiles/TILES_JAZZ/Plat8.png", true };//
				// TODO CHANGE PATH
				tilePath[(int)ObjectType::JazzDestructiblePlateformBase] = { "../../../res/Tiles/TILES_JAZZ/Destructible.png", true };//
				tilePath[(int)ObjectType::DestructibleVent] = { "../../../res/Tiles/TILES_JAZZ/Destructible_projectile.png", true };//
			}

			//Metal
			{
				tilePath[(int)ObjectType::MetalLeftPlatform] = { "../../../res/Tiles/TILES_METAL/Plat2.png", true };//
				tilePath[(int)ObjectType::MetalMiddlePlatform1] = { "../../../res/Tiles/TILES_METAL/Plat4.png", true };//
				tilePath[(int)ObjectType::MetalMiddlePlatform2] = { "../../../res/Tiles/TILES_METAL/Plat1.png", true };//
				tilePath[(int)ObjectType::MetalRightPlatform] = { "../../../res/Tiles/TILES_METAL/Plat3.png", true };//
				// TODO CHANGE PATH
				tilePath[(int)ObjectType::MetalDestructibleUP] = { "../../../res/Tiles/TILES_METAL/Destructible1.png", true };//
				tilePath[(int)ObjectType::MetalDestructibleMid] = { "../../../res/Tiles/TILES_METAL/Destructible2.png", true };//
				tilePath[(int)ObjectType::MetalDestructibleDown] = { "../../../res/Tiles/TILES_METAL/Destructible3.png", true };//
			}

			{
				// TODO CHANGE PATH
				tilePath[(int)ObjectType::PlateformPurple] = { "../../../res/Tiles/TILES_JAZZ/Plat7.png", true };//
				tilePath[(int)ObjectType::PlateformBlueMid] = { "../../../res/Tiles/TILES_JAZZ/Plat4.png", true };//
				tilePath[(int)ObjectType::PlateformBlueSide] = { "../../../res/Tiles/TILES_JAZZ/Plat3.png", true };//
				tilePath[(int)ObjectType::PlateformOrangeLeft] = { "../../../res/Tiles/TILES_JAZZ/Plat5.png", true };//
				tilePath[(int)ObjectType::PlateformOrangeRight] = { "../../../res/Tiles/TILES_JAZZ/Plat6.png", true };//
			}
		}
	}

	m_Level = new Level("../../../res/Levels/Niveau.txt", this);

	//Player
	m_Player = CreateRectangle<Player>(155, 225, sf::Color::Green, new AABBCollider(155, 225));
	m_Player->SetPosition(6272, 4864);
	//m_Player->SetPosition(0, 0);
	m_Player->SetSpeed(m_Player->GetMinSpeed());
	m_Player->SetRigidBody(true);
	m_Player->SetGravityStrength(1200.f);
	m_Player->SetJumpStrength(750);

	GameManager::Get()->GetCamera()->SetFollowingEntity(m_Player);
	GameManager::Get()->GetCamera()->Zoom(2.f);
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
		
		if (event.mouseButton.button == sf::Keyboard::Q)
		{
			//std::cout << "q est relaché" << std::endl;
			MoveLeft = false;
			m_Player->SetSpeed(0);
			m_Player->SetDirection(0, m_Player->GetPosition().y, 0);
		}

		if (event.mouseButton.button == sf::Keyboard::Space )
		{
			//std::cout << "espace est relaché" << std::endl;
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
		//std::cout << "d est pressé" << std::endl;
		m_Player->MoveRight(GetDeltaTime());
		m_Player->SetRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		//std::cout << "q est pressé" << std::endl;
		m_Player->MoveLeft(GetDeltaTime());
		m_Player->SetLeft();
	}
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 10)
	{
		//std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << std::endl;
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
		//std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << std::endl;
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
