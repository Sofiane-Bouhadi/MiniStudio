#pragma once
#include "GravityEntity.h"

class Player : public GravityEntity 
{
private :

	int m_life = 100;

	bool IsAlive = true;

	float m_acceleration = 3000.f;
	float m_MaxSpeed = 300.f;
	float m_MinSpeed = 150.f;
	

public:

	void MoveRight(float deltatime);
	void MoveLeft(float delattime);

	void TakeDmg(int DamageTaken);

	float GetSpeed() { return mSpeed; }

	float GetMinSpeed() { return m_MinSpeed; }

	void OnCollision(Entity* pOther, CollidingSide collidingSide) override;

	void OnUpdate() override;

};