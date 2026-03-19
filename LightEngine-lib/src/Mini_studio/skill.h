#pragma once
#include "Entity.h"
#include "AABBCollider.h"

class Player;

class Skill : public Entity
{
private:

	int mana_cost = 3;
	bool unlocked = false;

	Entity shockwave;

public:

	void shockwave_attack();


	void Unlocking() { unlocked = true; };

	void OnInitialize()override;
	void OnUpdate()override;
	void OnDestroy()override;
};