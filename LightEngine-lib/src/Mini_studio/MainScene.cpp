#include "MainScene.h"
#include "Player.h"
#include "Utils.h"
#include "Debug.h"
#include <iostream>

void MainScene::OnInitialize() 
{
	m_Player = CreateEntity<Player>(10, sf::Color::Green);
	m_Player->SetPosition(100, 100);

}

void MainScene::OnEvent(const sf::Event& event)
{

		if (event.type == sf::Event::KeyPressed)
		{
			if (event.mouseButton.button == sf::Keyboard::D)
			{
				std::cout << "d est pressé" << std::endl;
				m_Player->MoveRight(GetDeltaTime());
			}

			if (event.mouseButton.button == sf::Keyboard::Q)
			{
				std::cout << "q est pressé" << std::endl;
			}

			if (event.mouseButton.button == sf::Keyboard::Space)
			{
				std::cout << "espace est pressé" << std::endl;
			}
		}
}

void MainScene::OnUpdate() 
{

	Debug::DrawCircle(m_Player->GetPosition().x, m_Player->GetPosition().y, 10, sf::Color::Green);
	
}
