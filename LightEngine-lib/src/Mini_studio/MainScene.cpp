#include "MainScene.h"
#include "Player.h"
#include "Utils.h"
#include "Debug.h"
#include <iostream>
#include "AABBCollider.h"
#include <SFML/Graphics/RectangleShape.hpp>

void MainScene::OnInitialize() 
{
	//Rectangle
	pEntity4 = CreateRectangle<Entity>(1280, 50, sf::Color::White, new AABBCollider(1280, 50));
	pEntity4->SetPosition(1280 / 2, 720);
	pEntity4->SetRigidBody(true);
	pEntity4->SetStatic(true);

	m_Player = CreateRectangle<Player>(155, 225, sf::Color::Green,new AABBCollider(155,225) );
	m_Player->SetPosition(100, 500);
	m_Player->SetSpeed(m_Player->GetMinSpeed());
	m_Player->SetRigidBody(true);
	m_Player->SetGravityStrength(300.f);
}

void MainScene::OnEvent(const sf::Event& event)
{
	
	bool MoveRight = false;
	bool MoveLeft = false;
	bool jump = false;



	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::D )
		{
			std::cout << "d est pressé" << std::endl;
			MoveRight = true;	
			
		}

		if (event.key.code == sf::Keyboard::Q )
		{
			std::cout << "q est pressé" << std::endl;
			MoveLeft = true;
			
		}

		if (event.key.code == sf::Keyboard::Space)
		{
			std::cout << "espace est pressé" << std::endl;
			
			jump = true;
		}
	}

	if (event.type == sf::Event::JoystickMoved || event.type == sf::Event::JoystickButtonPressed)
	{

		sf::Joystick::Axis axis = event.joystickMove.axis;

		if (sf::Joystick::getAxisPosition(0,axis) > 10 && axis == sf::Joystick::X)
		{
			std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << std::endl;
			MoveRight = true;
			
		}
		
		if (sf::Joystick::getAxisPosition(0, axis) < -10 && axis == sf::Joystick::X)
		{
			std::cout << sf::Joystick::getAxisPosition(0, sf::Joystick::X) << std::endl;
			MoveLeft = true;
		}

		if (sf::Joystick::getAxisPosition(0, sf::Joystick::X) < 10 && axis == sf::Joystick::X && -10 < sf::Joystick::getAxisPosition(0, sf::Joystick::X))
		{
			MoveRight = false;
			MoveLeft = false;
			m_Player->SetSpeed(0);
		}
		

		if ( sf::Joystick::isButtonPressed(0,0)) 
		{
			std::cout << "A est appuyé" << std::endl;
			jump = true;
		}

	}


	else if (event.type == sf::Event::KeyReleased || event.type == sf::Event::JoystickButtonReleased)
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

		if (event.mouseButton.button == sf::Keyboard::Space || sf::Event::JoystickButtonReleased == 0)
		{
			std::cout << "espace est relaché" << std::endl;
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
	
}

void MainScene::OnUpdate() 
{

	std::cout << "x:" << m_Player->GetPosition().x << " y: " << m_Player->GetPosition().y << " speed : " << m_Player->GetSpeed() <<  std::endl;
	
}
