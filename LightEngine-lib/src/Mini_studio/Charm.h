#pragma once
#include <string>

class Player;

class Charm
{
public:
	virtual ~Charm() = default;
	virtual void OnEquip(Player* player) = 0;
	virtual void OnUnequip(Player* player) = 0;
	virtual std::string GetName() const = 0;
};