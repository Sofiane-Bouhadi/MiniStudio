#include "IA_Enemies.h"

void IA::live() {
	enemies enemy(100,10,10,10,10,10,10);

	float distence = enemy.telemetrie();
	if (distence <= 500) {
		enemy.AttackBull();
	}
}