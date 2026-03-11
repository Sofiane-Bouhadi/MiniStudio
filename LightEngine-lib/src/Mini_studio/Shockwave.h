#pragma once
#include "skill.h"

class enemies;

class Shockwave : public Skill
{
private:

	int damage = 5;
	float stun = 2.0f;

public:

	void Attack();
	void TakeDamage();

	void OnUpdate()override;
	void OnDestroy()override;
};