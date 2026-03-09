#pragma once
#include "Entity.h"

class Player : public Entity 
{
private :

	float m_acceleration = 10.f;
	float m_speed;
	float m_MaxSpeed = 20.f;

	sf::Vector2f m_pos;
public:
	void MoveRight(float deltatime);
};