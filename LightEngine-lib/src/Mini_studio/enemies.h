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
	void movementLigne(float x, float y, float toX, float toY, sf::Time time);
	enemies* pEntity;

};


