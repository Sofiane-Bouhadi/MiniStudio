#include "../Sample/SampleScene.h"
#include <iostream>

#pragma once
class enemies : public Entity
{
private:
	void OnCollision(Entity* other) override;
	float size_enemy;

	enemies* pEntity1;

protected:

public:
	void createEnemy(float x, float y, int size);
	void movement(float x, float y);
};


