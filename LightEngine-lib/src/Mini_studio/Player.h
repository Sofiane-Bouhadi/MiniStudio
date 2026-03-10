#pragma once
#include "Entity.h"

class Player : public Entity 
{
private :

	float m_acceleration = 3000.f;
	float m_MaxSpeed = 300.f;
	float m_MinSpeed = 150.f;

	

public:

	void MoveRight(float deltatime);
	void MoveLeft(float delattime);

	void jump(float deltatime);

	float GetMinSpeed() { return m_MinSpeed; }
};