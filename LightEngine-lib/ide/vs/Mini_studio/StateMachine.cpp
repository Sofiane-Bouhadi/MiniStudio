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
}

void StateMachine::effect() {

}