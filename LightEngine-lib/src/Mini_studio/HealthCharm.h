#pragma once
#include "Charm.h"

class HealthCharm : public Charm
{
private:
	int m_bonus = 10; 
public:
	HealthCharm(int bonus = 10) : m_bonus(bonus) {}
	void OnEquip(Player* player) override;
	void OnUnequip(Player* player) override;
	std::string GetName() const override { return "HealthCharm"; }
};