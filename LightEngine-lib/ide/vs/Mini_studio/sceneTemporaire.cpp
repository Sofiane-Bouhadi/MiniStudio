#include "sceneTemporaire.h"


void sceneTemporaire::OnInitialize() {

	enemies enemy(10,10,10,100,300,300);//error
	enemy.createEnemy(100, 100, 50);
}

void sceneTemporaire::OnEvent(const sf::Event& event) {
	enemies enemy;
}

void sceneTemporaire::OnUpdate() {
	enemies enemy;
	if (enemy.pEnemy != nullptr)
	{
		sf::Vector2f position = enemy.pEnemy->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Red);
	}
}