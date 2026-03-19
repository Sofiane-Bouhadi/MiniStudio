#include "sceneTemporaire.h"
#include <SFML/Graphics/RenderWindow.hpp>


void sceneTemporaire::OnInitialize() {
	sf::RenderWindow* window = nullptr;
	enemies enemy1(10, 10, 10, 100, 300, 300);
	enemy1.createEnemy(100, 100, 50);
}

void sceneTemporaire::OnEvent(const sf::Event& event) {
}

void sceneTemporaire::OnUpdate() {
	StateMachine stateMch;
	stateMch.haveChange = false;

	enemies enemy1(10, 10, 10, 100, 300, 300);
	Entity* target;
	Debug debuging;

	//enemy1.moveingInLigne(100, 100, 500, 500);
	//enemy1.AttackBull(target);

	//debug
	sf::Vector2f positionEn = enemy1.pEnemy->GetPosition();
	//debuging.DrawText(positionEn.x, positionEn.y, (std::string)"text",sf::Color::White);

	if (enemy1.pEnemy != nullptr)
	{
		sf::Vector2f position = enemy1.pEnemy->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Red);
	}
}