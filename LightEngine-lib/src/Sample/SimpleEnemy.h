#pragma once
#include "Entity.h"

class SimpleEnemy : public Entity
{
private:
	float mPatrolSpeed = 100.f;
	float mPatrolMinX = 0.f;
	float mPatrolMaxX = 200.f;
	bool mMovingRight = true;
	int mLife = 30;

public:
	void SetPatrolRange(float minX, float maxX) { mPatrolMinX = minX; mPatrolMaxX = maxX; }
	void SetPatrolSpeed(float speed) { mPatrolSpeed = speed; }

	void OnInitialize() override;
	void OnUpdate() override;
	void OnCollision(Entity* pOther, CollidingSide collidingSide) override;

	void TakeDamage(int damage);
	bool IsAlive() const { return mLife > 0; }
};
