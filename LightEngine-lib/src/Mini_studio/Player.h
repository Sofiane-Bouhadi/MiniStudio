#pragma once
#include "GravityEntity.h"
#include "projectile.h"
#include "skill.h"

class Player : public GravityEntity 
{
private :

	int m_life = 100;
	int nb_Jump = 2;

	bool IsAlive = true;

	float m_acceleration = 3000.f;
	float m_MaxSpeed = 300.f;
	float m_MinSpeed = 150.f;
	
	
	Entity* attack = nullptr; 
	bool IsAttack = false;
	float Attack_Cooldown = 2;

	Projectile* proj;
	bool IsShooting = false;
	float Shooting_Cooldown = 0.6f;

	Skill* shockwave;
	bool IsShockwave;
	float Shockwave_cooldown = 1;

	bool IsRight = false;
	bool IsLeft = false;
	
public:

	void MoveRight(float deltatime);
	void MoveLeft(float delattime);
	void DecreaseJump() { nb_Jump -= 1; }

	void SetRight();
	void SetLeft();
	void UnsetRight() {IsRight = false; }
	void UnsetLeft() { IsLeft = false; }

	void BaseAttack();
	void PlayerShoot();
	void PlayerShockwave();
	
	void TakeDmg(int DamageTaken);

	float GetSpeed() { return mSpeed; }
	int GetNbJump() { return nb_Jump; }
	bool GetAttack();
	float GetAttackCD() { return Attack_Cooldown; }
	float GetShootCD() { return Shooting_Cooldown; }

	float GetMinSpeed() { return m_MinSpeed; }

	void OnCollision(Entity* pOther, CollidingSide collidingSide) override;

	
	void OnInitialize() override;
	void OnUpdate() override;

};