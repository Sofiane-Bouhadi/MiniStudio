#include "SimpleEnemy.h"
#include <iostream>

void SimpleEnemy::OnInitialize()
{
	SetRigidBody(true);
	SetTag(2);
}

void SimpleEnemy::OnUpdate()
{
	sf::Vector2f pos = GetPosition(0.5f, 0.5f);

	if (mMovingRight)
	{
		SetDirection(1, 0, mPatrolSpeed);
		if (pos.x >= mPatrolMaxX)
			mMovingRight = false;
	}
	else
	{
		SetDirection(-1, 0, mPatrolSpeed);
		if (pos.x <= mPatrolMinX)
			mMovingRight = true;
	}
}

void SimpleEnemy::OnCollision(Entity* pOther, CollidingSide collidingSide)
{
	if (pOther->IsTag(1))
	{
		std::cout << "Enemy hit by player!" << std::endl;
	}
}

void SimpleEnemy::TakeDamage(int damage)
{
	mLife -= damage;
	if (mLife <= 0)
	{
		std::cout << "Enemy destroyed!" << std::endl;
		Destroy();
	}
}
