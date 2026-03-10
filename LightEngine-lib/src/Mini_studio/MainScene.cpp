#include "MainScene.h"
#include "Player.h"
#include "Utils.h"
#include "Debug.h"
#include <iostream>
#include "AABBCollider.h"
#include <SFML/Graphics/RectangleShape.hpp>

void MainScene::OnInitialize() 
{
	m_Player = CreateEntity<Player>(155, 225,new sf::RectangleShape, sf::Color::Green,new AABBCollider(155,225) );
	m_Player->SetPosition(100, 500);
	m_Player->SetSpeed(m_Player->GetMinSpeed());
	
}

void MainScene::OnEvent(const sf::Event& event)
{
	
	bool MoveRight = false;
	bool MoveLeft = false;



	if (event.type == sf::Event::KeyPressed || event.type == sf::Event::JoystickMoved || event.type == sf::Event::JoystickButtonPressed)
	{
		if (event.key.code == sf::Keyboard::D || sf::Joystick::getAxisPosition(0, sf::Joystick::X) > 0 || event.joystickButton.button == sf::Joystick::PovX > 0)
		{
			std::cout << "d est pressé" << std::endl;
			MoveRight = true;	
			
		}

		if (event.key.code == sf::Keyboard::Q || sf::Joystick::getAxisPosition(0, sf::Joystick::X) < 0 || sf::Joystick::PovY < 0)
		{
			std::cout << "q est pressé" << std::endl;
			MoveLeft = true;
			
		}

		if (event.key.code == sf::Keyboard::Space)
		{
			std::cout << "espace est pressé" << std::endl;
		}
	}

	else if (event.type == sf::Event::KeyReleased || event.type == sf::Event::JoystickMoved || event.type == sf::Event::JoystickButtonReleased)
	{
		if (event.key.code == sf::Keyboard::D || sf::Joystick::getAxisPosition(0, sf::Joystick::X) == 0 || sf::Joystick::PovX == 0)
		{
			std::cout << "d est relaché" << std::endl;
			MoveRight = false;
			m_Player->SetSpeed(0);
		}
		
		if (event.mouseButton.button == sf::Keyboard::Q || sf::Joystick::PovX == 0)
		{
			std::cout << "q est relaché" << std::endl;
			MoveLeft = false;
			m_Player->SetSpeed(0);
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
	
}

void MainScene::OnUpdate() 
{


	
}
