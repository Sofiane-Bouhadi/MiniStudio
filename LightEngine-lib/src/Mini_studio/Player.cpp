#include "Player.h"

void Player::MoveRight(float deltatime) 
{
	m_speed += m_acceleration * deltatime;
	if (m_speed > m_MaxSpeed) 
	{
		m_speed = m_MaxSpeed;
	}

	m_pos.x += m_speed * deltatime;
}