#include "IA_Enemies.h"

void IA::live(Entity* pTarget) {
	enemies enemy(100,10,10,10,10,10,10);

	float distence = enemy.telemetrie(pTarget);
	if (distence <= 500) {
		enemy.AttackBull(pTarget);
	}
}