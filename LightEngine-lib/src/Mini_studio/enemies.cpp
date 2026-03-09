#include "enemies.h"


void enemies::createEnemy(float x, float y, int size){
	pEntity1 = CreateEntity<enemies>(size, sf::Color::Red);
	pEntity1->SetPosition(x, y);
	pEntity1->SetRigidBody(true);
}

void enemies::movement(float x,float y) {


}

void enemies::OnCollision(Entity* other)
{
	std::cout << "Collision" << std::endl;
}