#pragma once
#include "Entity.h"

class Player : public Entity 
{
private :

	float m_acceleration = 3000.f;
	float m_MaxSpeed = 300.f;

	

public:

	void MoveRight(float deltatime);
	void MoveLeft(float delattime);
};