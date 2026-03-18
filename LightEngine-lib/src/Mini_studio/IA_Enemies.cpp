#include "IA_Enemies.h"

void IA::liveBull(enemies* pEnemy) {

	StateMachine state;
	sf::Vector2f positionEnemy = pEnemy-> GetPosition();
	float distence = pEnemy->telemetrie();
	if (distence <= 500 && state.canAttack && state.canMove) {
		pEnemy->AttackBull();
		state.change(5);
		state.effect(5);
	}
	else {
		pEnemy->moveingInLigne(0,100);
		state.change(1);
		state.effect(1);
	}
}

void IA::liveFall(enemies* pEnemy) {

	StateMachine state;
	sf::Vector2f positionEnemy = pEnemy->GetPosition();
	float distence = pEnemy->telemetrie();
	if (distence <= 500 && state.canAttack) {
		pEnemy->AttackFall();
		state.change(4);
		state.effect(4);
	}
	else {
		state.change(0);
		state.effect(0);
	}
}

void IA::livePunch(enemies* pEnemy) {

	StateMachine state;
	sf::Vector2f positionEnemy = pEnemy->GetPosition();
	float distence = pEnemy->telemetrie();
	if (distence <= 500 && state.canAttack) {
		pEnemy->AttackPunch();
		state.change(7);
		state.effect(7);
	}
	else {
		state.change(0);
		state.effect(0);
	}
}

void IA::liveShot(enemies* pEnemy) {

	StateMachine state;
	sf::Vector2f positionEnemy = pEnemy->GetPosition();
	float distence = pEnemy->telemetrie();
	if (distence <= 500 && state.canAttack) {
		pEnemy->AttackSmart();
		state.change(4);
		state.effect(4);
	}
	else {
		state.change(0);
		state.effect(0);
	}
}