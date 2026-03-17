#include "Attack.h"
#include "../LightEngine/Entity.h"
#include "Shoot.h"

#include <iostream>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Thread.hpp>
#include "StateMachine.h"

#pragma once
class enemies : public Entity
{
private:

	float size_enemy = 0;
	sf::Vector2f positionEnemy;

protected:

	int atk_size_Width { 0 };
	int atk_size_Height { 0 };
	float atk_speed { 0 };
	float m_speed { 0 };
	float m_x { 0 };
	float m_y { 0 };
	int m_PV{ 0 };

	int enemy_size{ 0 };

public:
	enemies* pEnemy = nullptr;
	sf::Vector2f pTarget;

	/*constructeur d'enemies*/
	enemies(int atkwidth = 0, int atkheight = 0, float atkspeed = 0, float speed = 0, float x = 0, float y = 0, int PV = 1)
		: atk_size_Width(atkwidth), atk_size_Height(atkheight), atk_speed(atkspeed), m_speed(speed), m_x(x), m_y(y), m_PV(PV)
	{};

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

};
