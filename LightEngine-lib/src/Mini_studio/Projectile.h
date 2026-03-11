#pragma once
#include "skill.h"

class Projectile : public Skill
{
private:

	int damage = 15;
	float speed = 4.0f;

public:

	void OnInitialize()override;
	void OnUpdate()override;
	void OnDestroy()override;

};
