#pragma once
#include "GravityEntity.h"
#include "Shoot.h"
#include <vector>
#include <memory>

class Charm;

class Player : public GravityEntity 
{
private :
	int m_life = 100;
	int m_maxLife = 100;
	int nb_Jump = 2;
	int PlayerTag = 1;

	int m_DashSpeed = 1500;
	float m_DashDelay = 0.5f;       
	float m_DashDuration = 0.18f;    
	float m_dashCooldownTimer = 0.f;
	float m_dashTimer = 0.f;
	bool mIsDashing = false;
	bool CanDash = true;

	float m_acceleration = 3000.f;
	float m_MaxSpeed = 300.f;
	float m_MinSpeed = 150.f;
	float Attack_Cooldown = 2.f;

	Shoot* shoot = nullptr;
	Entity* attack = nullptr; 

	bool IsAttack = false;
	bool IsRight = false;
	bool IsLeft = false;
	bool IsAlive = true;

	std::vector<Charm*> mCharms;
	Charm* mEquippedCharm = nullptr;
	int mCurrentCharmIndex = -1;



public:
	void DashRight(float deltatime);
	void DashLeft(float deltatime);
	void MoveRight(float deltatime);
	void MoveLeft(float deltatime);
	void DecreaseJump() { nb_Jump -= 1; }
	bool IsDashAvailable() const { return CanDash; };
	void SetRight();
	void SetLeft();
	void UnsetRight() { IsRight = false; }
	void UnsetLeft() { IsLeft = false; }

	void BaseAttack();
	void PlayerShoot();

	void TakeDmg(int DamageTaken);
	void RestoreHealth(int amount);
	int GetLife() const { return m_life; }

	void AddCharm(Charm* charm);       
	void EquipCharm(int index);                         
	void EquipCurrentCharm();                           
	void UnequipCharm();                                
	void CycleCharm();                                   

	float GetSpeed() { return mSpeed; }
	int GetNbJump() { return nb_Jump; }
	bool GetAttack();
	float GetAttackCD() { return Attack_Cooldown; }

	float GetMinSpeed() { return m_MinSpeed; }

	void OnCollision(Entity* pOther, CollidingSide collidingSide) override;

	void OnInitialize() override;
	void OnUpdate() override;
	~Player();
};