#include "enemies.h"


/*cree l'enemie*/
void enemies::createEnemy(float x, float y, int size){
	enemy_size = size;
	pEnemy = CreateEntity<enemies>(enemy_size, sf::Color::Red);
	pEnemy->SetPosition(x, y);
	pEnemy->SetRigidBody(true);
}

/*bouge en ligne*/
void enemies::moveingInLigne(float x,float y, float toX, float toY, sf::Time time) {
	GoToPosition(toX, toY,1.0f);
	sf::sleep(time);
	GoToPosition(x, y,1.0f);
	sf::sleep(time);
}

/*renvois un vecteur de l'entite cible*/
sf::Vector2f enemies::detection(GravityEntity* pTarget) {
	sf::Vector2f vectarget;
	positionEnemy = pEnemy->GetPosition();
	sf::Vector2f positiontarget = pTarget->GetPosition();
	vectarget.x = positionEnemy.x - positiontarget.x;
	vectarget.y = positionEnemy.y - positiontarget.y;
	vectarget.x = vectarget.x;
	vectarget.y = vectarget.y;

	return vectarget;
}

/*attack fall*/
void enemies::AttackFall(GravityEntity* pTarget) {
	sf::Vector2f positiontarget = pTarget->GetPosition();
	positionEnemy = pEnemy->GetPosition();
	if (positiontarget.y == positionEnemy.y + enemy_size / 2 || positiontarget.y == positionEnemy.y - enemy_size / 2) {
		GoToPosition(positionEnemy.x, positiontarget.y, 1.0f);
	}
}

/*attack bulldozer*/
void enemies::AttackBull(GravityEntity* pTarget) {
	sf::Vector2f positiontarget = pTarget->GetPosition();
	positionEnemy = pEnemy->GetPosition();
	if (positiontarget.x == positionEnemy.x + enemy_size / 2 || positiontarget.x == positionEnemy.x - enemy_size / 2) {
		if (telemetrie(pTarget)==(float)500)
		GoToPosition(positiontarget.x, positionEnemy.y, 1.0f);
	}
}


/*char, a 11 heures, distance: a 400m .(War thunder reference)*/
float enemies::telemetrie(GravityEntity* pTarget) {
	sf::Vector2f positiontarget = pTarget->GetPosition();
	positionEnemy = pEnemy->GetPosition();
	float AC = positionEnemy.x - positiontarget.x;
	float BC = positionEnemy.y - positiontarget.y;
	float AB = sqrt(AC*AC + BC*BC);
	return AB;
}






/*... serieux, tu ne sais pas ce que "OnCollision" fait... :/ */
void enemies::OnCollision(GravityEntity* other)
{
	std::cout << "Collision" << std::endl;
}



//--------------------------------------------------------------peut-etre-utile------------------------------------------------------------------------------------------------------


/*attaque de manier inteligente grace a detection ou a un paterne base sur la rose des vents*/
void enemies::attackDirection(bool smart, bool vert_N, bool vert_S, bool hori_E, bool hori_W, bool diag_NE, bool diag_NW, bool diag_SE, bool diag_SW) {
	GravityEntity* pTarget;

	float dist = telemetrie(pTarget);
	if (dist == (float)400) {
		positionEnemy = pEnemy->GetPosition();
		/* x et y sont les coordonee de l'enemi */
	}
	if (smart) {
		/*visé precise*/
		sf::Vector2f vectarget = detection(pTarget);

		//launchAttack(vectarget.x, vectarget.y);
	}
	else {
		if (vert_N) {/* attaque verticale vers le haut(N) */
			//launchAttack(-1, 0);
		}
		if (vert_S) {/* attaque verticale vers le bas(S) */
			//launchAttack(1, 0);
		}
		if (hori_E) {/* attaque horisontal vers la droite(E) */
			//launchAttack(0, 1);
		}
		if (hori_W) {/* attaque horisontale vers la gauche(W) */
			//launchAttack(0, -1);
		}

		if (diag_NE) {/* attaque en diagonale vers le haut(N) a droite(E) */
			//launchAttack(-1, 1);
		}
		if (diag_NW) {/* attaque en diagonale vers le haut(N) a gauche(W) */
			//launchAttack(-1, -1);
		}
		if (diag_SW) {/* attaque en diagonale vers le bas(S) a gauche(W) */
			//launchAttack(1, -1);
		}
		if (diag_SE) {/* attaque en diagonale vers le bas(S) a droite(E) */
			//launchAttack(1, 1);
		}
	}
}