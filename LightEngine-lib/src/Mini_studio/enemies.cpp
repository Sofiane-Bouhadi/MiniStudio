#include "enemies.h"
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Thread.hpp>


void enemies::createEnemy(float x, float y, int size){
	pEntity = CreateEntity<enemies>(size, sf::Color::Red);
	pEntity->SetPosition(x, y);
	pEntity->SetRigidBody(true);
}

void enemies::movementLigne(float x,float y, float toX, float toY, sf::Time time) {
	GoToPosition(toX, toY);
	sf::sleep(time);
	GoToPosition(x, y);
}

void enemies::OnCollision(Entity* other)
{
	std::cout << "Collision" << std::endl;
}