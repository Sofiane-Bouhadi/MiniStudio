#include "StateMachine.h"

void StateMachine::change(int nbr) {

	if (nbr == 0) {
		state(Idle);
	}
	else if (nbr == 1) {
		state(Moving);
	}
	else if (nbr == 2) {
		state(Reload);
	}
	else if (nbr == 3) {
		state(Stun);
	}
	else if (nbr == 4) {
		state(AttackFall);
	}
	else if (nbr == 5) {
		state(AttackBull);
	}
	else if (nbr == 6) {
		state(AttackSmart);
	}
	else if (nbr == 7) {
		state(AttackPunch);
	}
	else if (nbr == 8) {
		state(AttackPatern);
	}
	effect(nbr);
}

bool StateMachine::verifingState(int nbr) {
	return true;
}





void StateMachine::effect(int nbr) {
	if (nbr == 0 && canIdle == true) {
		//can idle
		canIdle = true;
		//can attack
		canAttack = true;
		//can realod
		canReload = true;
		//can move
		canMove = true;
	}
	else if (nbr == 1 && canMove == true) {
		//can idle
		canIdle = true;
		//can attack
		canAttack = true;
		//can realod
		canReload = true;
		//can move
		canMove = true;
	}
	else if (nbr == 2 && canReload == true) {
		//can idle
		canIdle = true;
		//can not attack
		canAttack = false;
		//can not realod
		canReload = false;
		//can move
		canMove = true;
	}
	else if (nbr == 3) {
		//can not idle
		canIdle = false;
		//can not attack
		canAttack = false;
		//can not realod
		canReload = false;
		//can not move
		canMove = false;
	}
	else if (nbr == 4 && canAttack == true) {
		//can not idle
		canIdle = false;
		//can attack
		canAttack = true;
		//can not realod
		canReload = false;
		//can not move
		canMove = false;
	}
	else if (nbr == 5 && canAttack == true && canMove == true) {
		//can idle
		canIdle = true;
		//can attack
		canAttack = true;
		//can not realod
		canReload = false;
		//can move
		canMove = true;
	}
	else if (nbr == 6 && canAttack == true) {
		//can idle
		canIdle = true;
		//can attack
		canAttack = true;
		//can realod
		canReload = true;
		//can move
		canMove = true;
	}
	else if (nbr == 7 && canAttack == true) {
		//can idle
		canIdle = true;
		//can attack
		canAttack = true;
		//can realod
		canReload = true;
		//can not move
		canMove = false;
	}
	else if (nbr == 8 && canAttack == true) {
		//can idle
		canIdle = true;
		//can attack
		canAttack = true;
		//can realod
		canReload = true;
		//can move
		canMove = true;
	}
}