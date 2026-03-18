#include "Attack.h"
#include "../LightEngine/Entity.h"
#include "Shoot.h"
#include "CircleCollider.h"
#include "Player.h"

#include <iostream>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Thread.hpp>
#include "StateMachine.h"

#pragma once
class enemies : public GravityEntity
{
private:

	

protected:
	int m_PV{ 5 };

	int enemy_size{ 0 };

public:
	enemies* pEnemy = nullptr;
	sf::Vector2f pTarget;
	float size_enemy = 0;
	sf::Vector2f positionEnemy;

	void OnCollision(Entity* pOther, CollidingSide collidingSide);

	void choix(int nbr);

	void init();

	/*cree des ennemis*/
	void createEnemy(float x, float y, int size);

	bool OnPlayerDetected();

	bool OnPlayerLost();

	bool OnDeath();

	bool OnHit();

	bool OnStateChanged();

	/*deplace l'ennemi en ligne*/
	void moveingInLigne(float x, float y, float toX, float toY);

	/*renvois un vecteur de l'entite cible*/
	sf::Vector2f detection();

	/*attaque de l'enemies*/
	void AttackFall();

	void AttackBull();

	void AttackPunch();

	void AttackSmart();

	float telemetrie();

	sf::Transformable* GetTransformable() { return mTransformable ; }
};
