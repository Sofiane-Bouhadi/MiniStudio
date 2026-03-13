#pragma once
#include "GravityEntity.h"

class Player : public GravityEntity 
{
private :

	int m_life = 100;
	int nb_Jump = 2;

	bool IsAlive = true;

	float m_acceleration = 3000.f;
	float m_MaxSpeed = 300.f;
	float m_MinSpeed = 150.f;
	
	Entity* attack = nullptr; //créer a l'initialisation et déplacment au bon endroit lors de l'appel de l'attaque 
public:

	void MoveRight(float deltatime);
	void MoveLeft(float delattime);
	void DecreaseJump() { nb_Jump -= 1; }


	void BaseAttack(Scene* scene);

	void TakeDmg(int DamageTaken);

	float GetSpeed() { return mSpeed; }
	int GetNbJump() { return nb_Jump; }

	float GetMinSpeed() { return m_MinSpeed; }

	void OnCollision(Entity* pOther, CollidingSide collidingSide) override;

	void OnUpdate() override;

};