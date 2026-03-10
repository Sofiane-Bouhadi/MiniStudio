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
	m_Player->SetPosition(100, 100);
	

}

void MainScene::OnEvent(const sf::Event& event)
{
	
	bool MoveRight = false;
	bool MoveLeft = false;

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::D)
		{
			std::cout << "d est pressé" << std::endl;
			MoveRight = true;	
			
		}

		if (event.mouseButton.button == sf::Keyboard::Q)
		{
			std::cout << "q est pressé" << std::endl;
			MoveLeft = true;
			
		}

		if (event.mouseButton.button == sf::Keyboard::Space)
		{
			std::cout << "espace est pressé" << std::endl;
		}
	}

	else if (event.type == sf::Event::KeyReleased )
	{
		if (event.key.code == sf::Keyboard::D) 
		{
			std::cout << "d est relaché" << std::endl;
			MoveRight = false;
			m_Player->SetSpeed(0);
		}
		
		if (event.mouseButton.button == sf::Keyboard::Q)
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
