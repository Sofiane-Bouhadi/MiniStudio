#include "Attack.h"
#include "../LightEngine/Entity.h"
#include <iostream>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Thread.hpp>
#include "StateMachine.h"

#pragma once
class enemies : public GravityEntity
{
private:

	float size_enemy;
	sf::Vector2f positionEnemy;

protected:

	int atk_size_Width { 0 };
	int atk_size_Height { 0 };
	float atk_speed { 0 };
	float m_speed { 0 };
	float m_x { 0 };
	float m_y { 0 };
	int m_PV{ 0 };
	int m_type{ 0 };

	int enemy_size{ 0 };

public:

	/*constructeur d'enemies*/
	enemies(int atkwidth, int atkheight, float atkspeed, float speed, float x, float y, int PV, int type)
		: atk_size_Width(atkwidth), atk_size_Height(atkheight), atk_speed(atkspeed), m_speed(speed), m_x(x), m_y(y), m_PV(PV), m_type(type)
	{};

	/*cree des ennemis*/
	void createEnemy(float x, float y, int size);

	/*deplace l'ennemi en ligne*/
	void moveingInLigne(float x, float y, float toX, float toY, sf::Time time);

	/*renvois un vecteur de l'entite cible*/
	sf::Vector2f detection(GravityEntity* cible);

	/*attaque de l'enemies*/
	void AttackFall(GravityEntity* pTarget);

	void AttackBull(GravityEntity* pTarget);

	float telemetrie(GravityEntity* pTarget);

	/**/
	void attackDirection(bool smart, bool vert_N, bool vert_S, bool hori_E, bool hori_W, bool diag_NE, bool diag_NW, bool diag_SE, bool diag_SW);

	/*tout est dans le nom.*/
	void OnCollision(GravityEntity* other) override;

	enemies* pEnemy;
};
