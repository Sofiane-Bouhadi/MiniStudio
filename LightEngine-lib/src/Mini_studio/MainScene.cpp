#include "MainScene.h"
#include "Player.h"
#include "Level.h"
#include "Boss.h"

#include "AABBCollider.h"

#include "Utils.h"
#include "Debug.h"
#include "Camera.h"

#include <iostream>
#include "AABBCollider.h"
#include <SFML/Graphics/RectangleShape.hpp>

void MainScene::Spawn(ObjectType objectType, float levelX, float levelY){}
void MainScene::SpawnCollider(float x, float y, float width, float height){}
void MainScene::OnInitialize() 
{
	srand(time(NULL));

	const char* pathFar = "../../../res/Layer_4.png";
	const char* pathMid = "../../../res/Layer_3.png";
	const char* pathNear = "../../../res/Layer_2.png";
	const char* pathClose = "../../../res/Layer_1.png";

	float winW = 5800;
	float winH = 4200;

	mParallaxFar = CreateSprite<Parallaxe>(winW, winH, pathFar, new AABBCollider(0, 0));
	mParallaxFar->SetPosition(0.f, 0.f, 0.f, 0.f);
	mParallaxFar->Init(this, 6.0f);

	mParallaxMid = CreateSprite<Parallaxe>(winW, winH, pathMid, new AABBCollider(0, 0));
	mParallaxMid->SetPosition(0.f, 0.f, 0.f, 0.f);
	mParallaxMid->Init(this, 4.0f);

	mParallaxNear = CreateSprite<Parallaxe>(winW, winH, pathNear, new AABBCollider(0, 0));
	mParallaxNear->SetPosition(0.f, 0.f, 0.f, 0.f);
	mParallaxNear->Init(this, 2.5f);

	mParallaxClose = CreateSprite<Parallaxe>(winW, winH, pathClose, new AABBCollider(0, 0));
	mParallaxClose->SetPosition(0.f, 0.f, 0.f, 0.f);
	mParallaxClose->Init(this, 1.5f);

	//Player
	m_Player = CreateRectangle<Player>(155, 225, sf::Color::Green, new AABBCollider(155, 225));
	m_Player->SetPosition(0, 0);


	m_Player->SetSpeed(m_Player->GetMinSpeed());
	m_Player->SetRigidBody(true);
	m_Player->SetGravityStrength(5000.f);
	m_Player->SetJumpStrength(1800);

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

	//m_Level = new Level("../../../res/Levels/Niveau.txt", this);

	GameManager::Get()->SetPlayer(m_Player);

	GameManager::Get()->GetCamera()->SetFollowingEntity(m_Player);
	GameManager::Get()->GetCamera()->Zoom(2.f);
	GameManager::Get()->GetCamera()->SetType(2);

	std::cout << "Main scene initialized" << std::endl;

	m_Level = new Level("../../../res/Levels/Niveau.txt", this);

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
			//std::cout << "espace est press�" << std::endl;
			jump = true;
			m_Player->DecreaseJump();
			
		}
		if (event.key.code == sf::Keyboard::E )
		{
			std::cout << "e est press�" << std::endl;
			shockwave = true;
			

		}
	}

	if (event.type == sf::Event::MouseButtonPressed) 
	{
		if (event.mouseButton.button == sf::Mouse::Button::Right)
		{
			//std::cout << "clic droit est appuy�" << std::endl;
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
			//std::cout << "A est appuy�" << std::endl;
			jump = true;
			m_Player->DecreaseJump();
		}

		if (sf::Joystick::isButtonPressed(0, 2))
		{
			//std::cout << "X est appuy�" << std::endl;
			base_attack = true;
		}
	}

	else if (event.type == sf::Event::KeyReleased)
	{
		if (event.key.code == sf::Keyboard::D)
		{
			//std::cout << "d est relach�" << std::endl;
			MoveRight = false;
			m_Player->SetSpeed(0);
			m_Player->SetDirection(0, m_Player->GetPosition().y, 0);
		}
		
		if (event.key.code == sf::Keyboard::Q)
		{
			//std::cout << "q est relach�" << std::endl;
			MoveLeft = false;
			m_Player->SetSpeed(0);
			m_Player->SetDirection(0, m_Player->GetPosition().y, 0);
		}

		if (event.key.code == sf::Keyboard::Space )
		{
			//std::cout << "espace est relach�" << std::endl;
			m_Player->SetSpeed(0);
			jump = false;
		}

		if (event.key.code == sf::Keyboard::E)
		{
			std::cout << "e est relach�" << std::endl;
			m_Player->SetSpeed(0);
			shockwave = false;
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
	if (enemy1 != nullptr)
	{
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
		//std::cout << "d est press�" << std::endl;
		m_Player->MoveRight(GetDeltaTime());
		if (m_Player->GetAttack() == false)
		{
			m_Player->SetRight();
		}

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		//std::cout << "q est press�" << std::endl;
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
		const char* player_sprite = "../../../res/Sprites/course_1.png";
		//std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << std::endl;
		m_Player->MoveLeft(GetDeltaTime());

		/*if (m_Player->GetAttack() == true)*/

		m_Player->SetLeft();
		m_Player->UnsetRight();
	}
}



