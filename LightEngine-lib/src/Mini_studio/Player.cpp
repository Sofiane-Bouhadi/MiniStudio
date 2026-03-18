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
}

void Player::SetLeft()
{
	IsLeft = true;
}


void Player::BaseAttack() 
{
	IsAttack = true;
	Attack_Cooldown = 2;
	
}

void Player::PlayerShoot() 
{
	IsShooting = true;
	Shooting_Cooldown = 3;


	if (IsRight)
	{
		proj = CreateSprite<Projectile>(136.f, 53.f, "../../../res/Sprites/projectile_right.png", new AABBCollider(136, 53));
		sf::Vector2f spawnPos = GetPosition(0.5f, 0.5f);
		proj->SetPosition(spawnPos.x, spawnPos.y, 0.5f, 0.5f);
		proj->SetOwnerTag(mTag);
		proj->SetProjectileSpeed(1000.f);
		proj->SetDirection(1, 0, proj->GetProjectileSpeed());
	
	}
	if (IsLeft)
	{
		proj = CreateSprite<Projectile>(136.f, 53.f, "../../../res/Sprites/projectile_left.png", new AABBCollider(136, 53));
		sf::Vector2f spawnPos = GetPosition(0.5f, 0.5f);
		proj->SetPosition(spawnPos.x, spawnPos.y, 0.5f, 0.5f);
		proj->SetOwnerTag(mTag);
		proj->SetProjectileSpeed(1000.f);
		proj->SetDirection(-1, 0, proj->GetProjectileSpeed());
		Shooting_Cooldown = 3;
	}
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

bool Player::GetAttack() 
{
	if (IsAttack) 
	{
		return true;
	}
	return false;
}


void Player::OnInitialize() 
{
	SetTag(1);

	Scene* scene = GetScene();

	attack = scene->CreateRectangle<Entity>(85, 30, sf::Color::Red, new AABBCollider(85, 30)); 
	attack->SetPosition(GetPosition().x, GetPosition().y);
	attack->SetTag(1);
}


void Player::OnUpdate() 
{
	

	if (m_life == 0)
	{
		IsAlive = false;
	}

	Attack_Cooldown -= GetDeltaTime();
	

	if (attack != nullptr && Attack_Cooldown < 0) 
	{
		attack->SetPosition(GetPosition().x, GetPosition().y);

	}


	if (IsAttack == true && Attack_Cooldown > 0) 
	{
		
		if (IsRight) 
		{
			attack->SetPosition(GetPosition().x + 115, GetPosition().y);
			
		}
		if (IsLeft)
		{
			attack->SetPosition(GetPosition().x - 115, GetPosition().y);
			
		}
	}

	Shooting_Cooldown -= GetDeltaTime();

	if (Shooting_Cooldown > 0.f)
	{
		IsShooting = false;
	}

}