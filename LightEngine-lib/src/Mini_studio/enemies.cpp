#include "enemies.h"
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Thread.hpp>


void enemies::createEnemy(float x, float y, int size){
	pEnemy = CreateEntity<enemies>(size, sf::Color::Red);
	pEnemy->SetPosition(x, y);
	pEnemy->SetRigidBody(true);
}

void enemies::moveingInLigne(float x,float y, float toX, float toY, sf::Time time) {
	GoToPosition(toX, toY);
	sf::sleep(time);
	GoToPosition(x, y);
}

void enemies::attack(bool smart,bool vertN,bool vertS,bool horiE, bool horiW,bool diagNE, bool diagNW, bool diagSE, bool diagSW) {
	if (smart) {
		// teleguider
	}else {
		if (vertN) {
		
		}
		if (vertS) {
		
		}
		if (horiE) {
		
		}
		if (horiW) {
		
		}

		if (diagNE) {
		
		}
		if (diagNW) {
		
		}
		if (diagSW) {
		
		}
		if (diagSE) {
		
		}
	}
}

void launchAttack( int up, int down, int left, int right) {

}

void enemies::OnCollision(Entity* other)
{
	std::cout << "Collision" << std::endl;
}