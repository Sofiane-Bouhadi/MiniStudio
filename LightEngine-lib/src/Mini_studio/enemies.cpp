#include "enemies.h"

/*facilite l'utilisation de la state machine*/
void enemies::choix(int nbr) {
	StateMachine state;
	state.change(nbr);
}

void enemies::init() {
	Player player;
	pTarget = player.GetPosition();

}

void enemies::OnCollision(Entity* pOther, CollidingSide collidingSide)
{
	if (collidingSide == Bottom)
	{
		mYVelocity = 0.f;
	}

}

/*cree l'enemie*/
void enemies::createEnemy(float x, float y, int size){

	enemy_size = size;

}

/*evenement OnPlayerDetected*/
bool enemies::OnPlayerDetected() {
	if (telemetrie() <= 500) {
		return true;
	}else {
		return false;
	}
}

/*evenement OnPlayerLost*/
bool enemies::OnPlayerLost() {
	if (telemetrie() >= 500) {
		return true;
	}
	else {
		return false;
	}
}

/*evenement OnDeath*/
bool enemies::OnDeath(){
	if (m_PV <= 0) {
		return true;
	}else { 
		return false; 
	}
}

/*evenement OnHit*/ //need to be corrctly recode
bool enemies::OnHit() {
	if (true) {
		return true;
	}else {
		return false;
	}
}

/*evenement OnStateChanged*/
bool enemies::OnStateChanged() {
	StateMachine stateMch;
	if (stateMch.haveChange) {
		return true;
	}else {
		return false;
	}
}

/*bouge en ligne*/
void enemies::moveingInLigne(float x,float y, float toX, float toY) {
	bool ismoving = false;
	positionEnemy = pEnemy->GetPosition();
	if (positionEnemy.x != toX && positionEnemy.y != toY){ 
		GoToPosition(toX, toY,1.0f);
	}
	if (positionEnemy.x != x && positionEnemy.y != y){
		GoToPosition(x, y, 1.0f);
	}
}

/*renvois un vecteur de l'entite cible*/
sf::Vector2f enemies::detection() {
	sf::Vector2f vectarget;
	positionEnemy = pEnemy->GetPosition();
	sf::Vector2f positiontarget = pTarget;
	vectarget.x = positionEnemy.x - positiontarget.x;
	vectarget.y = positionEnemy.y - positiontarget.y;
	vectarget.x = vectarget.x;
	vectarget.y = vectarget.y;

	return vectarget;
}

/*attack fall*/
void enemies::AttackFall() {
	sf::Vector2f positiontarget = pTarget;
	positionEnemy = pEnemy->GetPosition();
	if (positiontarget.y == positionEnemy.y + enemy_size / 2 || positiontarget.y == positionEnemy.y - enemy_size / 2) {
		GoToPosition(positionEnemy.x, positiontarget.y, 1.0f);
	}
}

/*attack bulldozer*/
void enemies::AttackBull() {
	sf::Vector2f positiontarget = pTarget;
	positionEnemy = pEnemy->GetPosition();
	if (positiontarget.x == positionEnemy.x + enemy_size / 2 || positiontarget.x == positionEnemy.x - enemy_size / 2) {
		if (telemetrie()==(float)500)
		GoToPosition(positiontarget.x, positionEnemy.y, 1.0f);
	}
}

/*attack punch*/
void enemies::AttackPunch() {
	sf::Vector2f positiontarget = pTarget;
	positionEnemy = pEnemy->GetPosition();
	if (positiontarget.x == positionEnemy.x + enemy_size / 2 || positiontarget.x == positionEnemy.x - enemy_size / 2) {
		if (telemetrie() == (float)50) {
			/*attack close fight*/
		}
	}
}

/*attack smart*/
void enemies::AttackSmart() {
	sf::Vector2f positiontarget = pTarget;
	positionEnemy = pEnemy->GetPosition();
	if (telemetrie() == (float)500){
		/*attack smart*/
	}
}

/*char, a 11 heures, distance: a 400m .(War thunder reference)*/
float enemies::telemetrie() {
	sf::Vector2f positiontarget = pTarget;
	positionEnemy = pEnemy->GetPosition();
	float AC = positionEnemy.x - positiontarget.x;
	float BC = positionEnemy.y - positiontarget.y;
	float AB = sqrt(AC*AC + BC*BC);
	return AB;
}
