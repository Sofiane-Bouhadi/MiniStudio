#pragma once
class StateMachine
{
private:

protected:
	enum state {
		Idle,            /*0 = ne bouge pas, ne fait rien.*/
		Moving,          /*1 = bouge.*/
		Reload,          /*2 = recharge.*/
		Stun,            /*3 = est incapable de bouger ou de faire quoi que se soit.*/
		AttackFall,      /*4 = attaque de la zone metal ennemi 1.*/
		AttackBull,      /*5 = attaque de la zone metal ennemi 2.*/
		AttackSmart,     /*6 = attaque de la zone jazz ennemi 1.*/
		AttackPunch,     /*7 = attaque de la zone jazz ennemi 2.*/
		AttackPatern,    /*8 = merci de spesifiez le paterne grace a la rose des vents (N,S,E,W).*/
		
		count
	};

public:

	void change(int nbr);

	void effect();

};

