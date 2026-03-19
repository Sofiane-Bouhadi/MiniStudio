#include "HealthCharm.h"
#include "Player.h"

void HealthCharm::OnEquip(Player* player)
{

	if (player) player->RestoreHealth(m_bonus);
}

void HealthCharm::OnUnequip(Player* player)
{

	(void)player;
}