#pragma once
#include "skill.h"

class enemies;

class Shockwave : public Skill
{
private:

	int m_damage = 5;
	float m_stun = 2.0f;

public:

	int GetDamage() { return m_damage; };
	void SetDamage(int dmg) { m_damage = dmg; };

	void Attack();
	void TakeDamage();

	void OnUpdate()override;
	void OnDestroy()override;
};