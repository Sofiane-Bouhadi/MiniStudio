#include "Player.h"
#include "AABBCollider.h"

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

void Player::SetRight() 
{
	IsRight = true;
	Side_Cooldown = 2;
}

void Player::SetLeft()
{
	IsLeft = true;
	Side_Cooldown = 2;
}


void Player::BaseAttack() 
{
	IsAttack = true;
	Attack_Cooldown = 2;
}

void Player::OnCollision(Entity* pOther, CollidingSide collidingSide)
{
	if (collidingSide == Bottom) 
	{
		mYVelocity = 0.f;
		nb_Jump = 2;
	}
		
}

void Player::TakeDmg(int DamageTaken) 
{
	m_life -= DamageTaken;

}


void Player::OnInitialize() 
{
	Scene* scene = GetScene();

	attack = scene->CreateRectangle<Entity>(85, 30, sf::Color::Red, new AABBCollider(85, 30)); 
	attack->SetPosition(GetPosition().x, GetPosition().y);
}


void Player::OnUpdate() 
{
	

	if (m_life == 0)
	{
		IsAlive = false;
	}

	Attack_Cooldown -= GetDeltaTime();
	Side_Cooldown -= GetDeltaTime();

	if (attack != nullptr && Attack_Cooldown < 0)
		attack->SetPosition(GetPosition().x, GetPosition().y);

	

	else if (IsAttack == true && Attack_Cooldown > 0) 
	{
		if (IsRight == true && Side_Cooldown < 0) 
		{
			attack->SetPosition(GetPosition().x + 85, GetPosition().y);
			
		}
		if (IsLeft == true && Side_Cooldown < 0)
		{
			attack->SetPosition(GetPosition().x - 85, GetPosition().y);
			
		}
	}

}