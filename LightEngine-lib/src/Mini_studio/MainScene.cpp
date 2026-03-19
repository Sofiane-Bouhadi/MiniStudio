#include "MainScene.h"
#include "Player.h"
#include "Utils.h"
#include "Debug.h"
#include <iostream>
#include "AABBCollider.h"
#include <SFML/Graphics/RectangleShape.hpp>

void MainScene::Spawn(ObjectType objectType, float levelX, float levelY){}
void MainScene::SpawnCollider(float x, float y, float width, float height){}
void MainScene::OnInitialize() 
{
	//Rectangle
	pEntity4 = CreateRectangle<Entity>(1280, 50, sf::Color::White, new AABBCollider(1280, 50));
	pEntity4->SetPosition(1280 / 2, 720);
	pEntity4->SetRigidBody(true);
	pEntity4->SetStatic(true);

	m_Player = CreateRectangle<Player>(155, 225, sf::Color::Green,new AABBCollider(155,225) );
	m_Player->SetPosition(100, 500);

	//Player
	m_Player = CreateSprite<Player>(155, 225, player_sprite,new AABBCollider(155,225) );
	m_Player->SetPosition(1000, 300);
	m_Player->SetSpeed(m_Player->GetMinSpeed());
	m_Player->SetRigidBody(true);
	m_Player->SetGravityStrength(300.f);
	m_Player->SetJumpStrength(300);

	enemy1= CreateSprite<enemies>(128, 128,R"(..\..\..\asset\ennemi smart\idle_1.png)", new AABBCollider(128, 128));
	enemy1->SetRigidBody(true);
	enemy1->SetPosition(100, 100);
	enemy1->init(enemy1, m_Player);
	enemy1->SetGravityStrength(0);
	//Platform
	Entity* entity = CreateRectangle<Entity>(3000, 100, sf::Color::White, new AABBCollider(3000, 100));
	entity->SetStatic(true);
	entity->SetRigidBody(true);
	entity->SetPosition(0, 720);

	enemy2 = CreateSprite<enemies>(128, 128, R"(..\..\..\asset\ennemi stamp\idle_1.png)", new AABBCollider(128, 128));
	enemy2->SetRigidBody(true);
	enemy2->SetPosition(200, 300);
	enemy2->init(enemy2, m_Player);
	enemy2->SetGravityStrength(0);

	enemy3 = CreateSprite<enemies>(128, 128, R"(..\..\..\asset\ennemi stamp\idle_1.png)", new AABBCollider(128, 128));
	enemy3->SetRigidBody(true);
	enemy3->SetPosition(350, 300);
	enemy3->init(enemy3, m_Player);
	enemy3->SetGravityStrength(0);

	enemy4 = CreateSprite<enemies>(128, 128, R"(..\..\..\asset\ennemi smart\idle_1.png)", new AABBCollider(128, 128));
	enemy4->SetRigidBody(true);
	enemy4->SetPosition(400, 100);
	enemy4->init(enemy4, m_Player);
	enemy4->SetGravityStrength(0);
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
	m_Player->SetGravityStrength(2500.f);
	m_Player->SetJumpStrength(1500.f);

	GameManager::Get()->GetCamera()->SetFollowingEntity(m_Player);
	GameManager::Get()->GetCamera()->Zoom(2.f);
}

void MainScene::OnEvent(const sf::Event& event)
{
	

	bool MoveRight = false;
	bool MoveLeft = false;
	bool jump = false;
	bool base_attack = false;
	bool shoot = false;
	bool shockwave = false;
	bool potion = false;
	
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
		if (event.key.code == sf::Keyboard::A)
		{
			std::cout << "a est press�" << std::endl;
			potion = true;

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

		if (sf::Joystick::isButtonPressed(0, 5))
		{
			//std::cout << "X est appuy�" << std::endl;
			base_attack = true;
		}
			std::cout << "RB est appuy�" << std::endl;
			base_attack = true;
		}
		
		if (sf::Joystick::isButtonPressed(0, 3) && m_Player->GetShootCD() <= 0.f)
		{
			std::cout << "Y est appuy�" << std::endl;
			 shoot = true;
		}

		if (sf::Joystick::isButtonPressed(0, 1) && m_Player->GetShootCD() <= 0.f)
		{
			std::cout << "Y est appuy�" << std::endl;
			shockwave = true;
		}

		if (sf::Joystick::isButtonPressed(0, 2))
		{
			std::cout << "X est appuy�" << std::endl;
			potion = true;
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
			shockwave = false;
		}

		if (event.key.code == sf::Keyboard::A)
		{
			std::cout << "a est relach�" << std::endl;
			potion = false;
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

			potion = false;
		}

		if (sf::Event::JoystickButtonReleased == 0) 
		{
			m_Player->SetSpeed(0);
			jump = false;}
			jump = false;
		}

		if (sf::Event::JoystickButtonReleased == 3)
		{
			shoot = false;

		}
		if (sf::Event::JoystickButtonReleased == 1)
		{
			shockwave = false;

		}
		if (sf::Event::JoystickButtonReleased == 5)
		{
			base_attack = false;

		}

	}
	if (jump) {
		m_Player->Jump();
	}

	if (base_attack){
		m_Player->BaseAttack();
	}
	if (shoot) 
	{
		m_Player->PlayerShoot();
	}
	if (shockwave)
	{
		m_Player->PlayerShockwave();
	}
	if (potion) 
	{
		m_Player->UsePotion();
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
		//std::cout << "d est press�" << std::endl;
		m_Player->MoveRight(GetDeltaTime());
		if (m_Player->GetAttack() == false) 
		m_Player->SetRight();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		//std::cout << "q est press�" << std::endl;
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
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		//std::cout << "q est press�" << std::endl;
		//std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << std::endl;
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


	/*std::cout << "x:" << m_Player->GetPosition().x << " y: " << m_Player->GetPosition().y << " speed : " << m_Player->GetSpeed() <<  std::endl;*/
	
}
