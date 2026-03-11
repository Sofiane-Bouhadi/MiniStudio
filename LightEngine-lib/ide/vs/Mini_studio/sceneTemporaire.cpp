#include "sceneTemporaire.h"
#include <SFML/Graphics/RenderWindow.hpp>


void sceneTemporaire::OnInitialize() {
	sf::RenderWindow* window = nullptr;


	//enemies enemy(10,10,10,100,300,300);
	//enemy.createEnemy(100, 100, 50);
}

void sceneTemporaire::OnEvent(const sf::Event& event) {
	//enemies enemy(10, 10, 10, 100, 300, 300);
}

void sceneTemporaire::OnUpdate() {
	enemies enemy(10, 10, 10, 100, 300, 300, 0, 0);
	if (enemy.pEnemy != nullptr)
	{
		sf::Vector2f position = enemy.pEnemy->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Red);
	}
}