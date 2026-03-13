#pragma once
#include "GravityEntity.h"

class Player : public GravityEntity 
{
private :

	float m_acceleration = 3000.f;
	float m_MaxSpeed = 300.f;
	float m_MinSpeed = 150.f;
	float m_Impulsion = 200.f;
	

public:

	void MoveRight(float deltatime);
	void MoveLeft(float delattime);

	void jump();

	float GetMinSpeed() { return m_MinSpeed; }

	void OnCollision(Entity* pOther, CollidingSide collidingSide);

	/*void OnUpdate() override;*/

};