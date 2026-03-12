#pragma once 
#include "Entity.h"

class Projectile : public Entity
{
private:

	int m_damage = 10;

public:

	int GetDamageP() { return m_damage; };
	void SetDamageP(int dmg) { m_damage = dmg; };

};