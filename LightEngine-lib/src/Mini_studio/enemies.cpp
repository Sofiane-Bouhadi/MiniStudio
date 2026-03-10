#include "enemies.h"



void enemies::createEnemy(float x, float y, int size){
	pEnemy = CreateEntity<enemies>(size, sf::Color::Red);
	pEnemy->SetPosition(x, y);
	pEnemy->SetRigidBody(true);
}

void enemies::moveingInLigne(float x,float y, float toX, float toY, sf::Time time) {
	GoToPosition(toX, toY);
	sf::sleep(time);
	GoToPosition(x, y);
	sf::sleep(time);
}

void enemies::attackDirection(bool smart,bool vert_N,bool vert_S,bool hori_E,bool hori_W,bool diag_NE,bool diag_NW,bool diag_SE,bool diag_SW) {
	
	positionEnemy = pEnemy->GetPosition();
	/* x et y sont les coordonee de l'enemey */
	
	if (smart) {
		
		// teleguider
	}else {
		if (vert_N) {/* attaque verticale vers le haut(N) */ 
			launchAttack(-1, 0);
		}
		if (vert_S) {/* attaque verticale vers le bas(S) */
			launchAttack( 1, 0);
		}
		if (hori_E) {/* attaque horisontal vers la droite(E) */
			launchAttack( 0, 1);
		}
		if (hori_W) {/* attaque horisontale vers la gauche(W) */
			launchAttack( 0,-1);
		}

		if (diag_NE) {/* attaque en diagonale vers le haut(N) a droite(E) */
			launchAttack(-1, 1);
		}
		if (diag_NW) {/* attaque en diagonale vers le haut(N) a gauche(W) */
			launchAttack(-1,-1);
		}
		if (diag_SW) {/* attaque en diagonale vers le bas(S) a gauche(W) */
			launchAttack( 1,-1);
		}
		if (diag_SE) {/* attaque en diagonale vers le bas(S) a droite(E) */
			launchAttack( 1, 1);
		}
	}
}

void enemies::launchAttack( float vectx, float vecty) {
	float x = positionEnemy.x;
	float y = positionEnemy.y;
	attack attack(atk_size_Width, atk_size_Height, x, y, vectx * atk_speed, vecty * atk_speed);
}

void enemies::OnCollision(Entity* other)
{
	std::cout << "Collision" << std::endl;
}