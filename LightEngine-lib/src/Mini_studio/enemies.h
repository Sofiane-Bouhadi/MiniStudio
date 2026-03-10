#include "../Sample/SampleScene.h"
#include <iostream>

#pragma once
class enemies : public Entity
{
private:
	void OnCollision(Entity* other) override;
	float size_enemy;

protected:

public:
	void createEnemy(float x, float y, int size);
	void moveingInLigne(float x, float y, float toX, float toY, sf::Time time);
	void attack(bool smart, bool vertN, bool vertS, bool horiE, bool horiW, bool diagNE, bool diagNW, bool diagSE, bool diagSW);
	enemies* pEnemy;
};


