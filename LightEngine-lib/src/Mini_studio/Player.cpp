#include "Player.h"

void Player::MoveRight(float deltatime) 
{
	mSpeed += m_acceleration * deltatime;
	if (mSpeed > m_MaxSpeed) 
	{
		mSpeed = m_MaxSpeed;
	}

	SetDirection(1, 0, mSpeed);
}

void Player::MoveLeft(float deltatime)
{
	
	mSpeed += m_acceleration * deltatime;
	if (mSpeed > m_MaxSpeed)
	{
		mSpeed = m_MaxSpeed;
	}

	SetDirection(-1, 0, mSpeed);
}


void Player::OnCollision(Entity* pOther, CollidingSide collidingSide)
{
	if (collidingSide == Bottom)
		mYVelocity = 0.f;
}

void Player::TakeDmg(int DamageTaken) 
{
	m_life -= DamageTaken;

}

void Player::OnUpdate() 
{
	if (m_life == 0)
	{
		IsAlive = false;
	}
}