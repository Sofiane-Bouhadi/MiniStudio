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
	if (IsShooting || IsShockwave)
		return;

	IsAttack = true;
	Attack_Cooldown = 2;
	
}

void Player::PlayerShoot() 
{
	if (IsAttack || IsShockwave)
		return;

	mana_stack -= 3;
	IsShooting = true;
	Shooting_Cooldown = 0.6f;


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
	}
}

void Player::PlayerShockwave() 
{
	if (IsAttack || IsShooting)
		return;

	mana_stack -= 3;
	IsShockwave = true;
	Shockwave_cooldown = 1;

	shockwave = CreateRectangle<Skill>(600, 600, sf::Color::Transparent, new AABBCollider(600, 600));
	shockwave->SetTag(1);
}

void Player::UsePotion() 
{
	nb_potion -= 1;
	m_life = 3;
}

void Player::OnCollision(Entity* pOther, CollidingSide collidingSide)
{
	if (collidingSide == Bottom) 
	{
		mYVelocity = 0.f;
		nb_Jump = 2;
	}	
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

	attack = scene->CreateRectangle<Entity>(85, 30, sf::Color::Transparent, new AABBCollider(85, 30)); 
	attack->SetPosition(GetPosition().x, GetPosition().y);
	attack->SetTag(1);

	Disc = scene->CreateSprite<Entity>(165, 165, disc_sprite, new AABBCollider(0, 0));

	LifeBar_back = scene->CreateSprite<Entity>(376, 70, "../../../res/hud/JAUGE_FOND.png", new AABBCollider(0, 0));
	LifeBar_top = scene->CreateSprite<Entity>(367, 56, "../../../res/hud/JAUGE_DESSUS.png", new AABBCollider(0, 0));
	LifeBar = scene->CreateSprite<Entity>(286, 40, life_sprite, new AABBCollider(0, 0));

	ManaBar = scene->CreateSprite<Entity>(204, 77, mana_sprite, new AABBCollider(0, 0));

}


void Player::OnUpdate() 
{
	Scene* scene = GetScene();

	if (m_life == 0)
	{
		IsAlive = false;
	}

	Attack_Cooldown -= GetDeltaTime();
	
	if (attack != nullptr && Attack_Cooldown < 0) 
	{
		IsAttack = false;
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

	if (Shooting_Cooldown < 0.f)
	{
		IsShooting = false;
		Shooting_Cooldown = 0.f;

	}

	Shockwave_cooldown -= GetDeltaTime();

	if (Shockwave_cooldown <= 0)
	{
		IsShockwave = false;
		if (shockwave != nullptr) 
		{
			shockwave->Destroy();
			shockwave = nullptr;
		}		
	}
	if (Shockwave_cooldown > 0 && IsShockwave && shockwave != nullptr)
	{
		shockwave->SetPosition(GetPosition().x, GetPosition().y);
	}

	sf::Vector2f cameraCenter = GameManager::Get()->GetCamera()->GetView()->getCenter();

	Disc->SetPosition(cameraCenter.x - 1140, cameraCenter.y - 570);
	LifeBar_back->SetPosition(Disc->GetPosition().x + 70, Disc->GetPosition().y - 70,0,0);
	LifeBar_top->SetPosition(Disc->GetPosition().x + 70, Disc->GetPosition().y - 70, 0, 0);
	LifeBar->SetPosition(Disc->GetPosition().x + 133, Disc->GetPosition().y - 62, 0, 0);
	ManaBar->SetPosition(Disc->GetPosition().x + 85, Disc->GetPosition().y - 5, 0, 0);



	if (nb_potion = 0 && Disc != nullptr)
	{
		Disc->Destroy();
		Disc = scene->CreateSprite<Entity>(165, 165, "../../../res/hud/VINYL_0.png", new AABBCollider(0, 0));
		Disc->SetPosition(cameraCenter.x - 1140, cameraCenter.y - 570);
	}

	if (nb_potion = 1 && Disc != nullptr)
	{
		Disc->Destroy();
		Disc = scene->CreateSprite<Entity>(165, 165, "../../../res/hud/VINYL_1.png", new AABBCollider(0, 0));
		Disc->SetPosition(cameraCenter.x - 1140, cameraCenter.y - 570);
	}
	if (nb_potion = 2  && Disc != nullptr) 
	{
		Disc->Destroy();
		Disc = scene->CreateSprite<Entity>(165, 165, "../../../res/hud/VINYL_2.png", new AABBCollider(0, 0));
		Disc->SetPosition(cameraCenter.x - 1140, cameraCenter.y - 570);
	}

	if (nb_potion = 3 && Disc != nullptr)
	{
		Disc->Destroy();
		Disc = scene->CreateSprite<Entity>(165, 165, "../../../res/hud/VINYL_FULL.png", new AABBCollider(0, 0));
		Disc->SetPosition(cameraCenter.x - 1140, cameraCenter.y - 570);
	}


	if (m_life = 1 && LifeBar != nullptr)
	{
			LifeBar->Destroy();
			LifeBar = scene->CreateSprite<Entity>(286, 40, "../../../res/hud/jdv3.png", new AABBCollider(0, 0));
			LifeBar->SetPosition(Disc->GetPosition().x + 133, Disc->GetPosition().y - 62, 0, 0);
	}
	if (m_life = 2 && LifeBar != nullptr)
	{
		LifeBar->Destroy();
		LifeBar = scene->CreateSprite<Entity>(286, 40, "../../../res/hud/jdv2.png", new AABBCollider(0, 0));
		LifeBar->SetPosition(Disc->GetPosition().x + 133, Disc->GetPosition().y - 62, 0, 0);
	}
	if (m_life = 3 && LifeBar != nullptr)
	{
		LifeBar->Destroy();
		LifeBar = scene->CreateSprite<Entity>(286, 40, "../../../res/hud/JAUGE_VIE.png", new AABBCollider(0, 0));
		LifeBar->SetPosition(Disc->GetPosition().x + 133, Disc->GetPosition().y - 62, 0, 0);
	}


	if (mana_stack = 0 && ManaBar != nullptr)
	{
		ManaBar->Destroy();
		ManaBar = scene->CreateSprite<Entity>(286, 40, "../../../res/hud/MANA_0.png", new AABBCollider(0, 0));
		ManaBar->SetPosition(Disc->GetPosition().x + 85, Disc->GetPosition().y - 5, 0, 0);
	}
	if (mana_stack = 1 && ManaBar != nullptr)
	{
		ManaBar->Destroy();
		ManaBar = scene->CreateSprite<Entity>(286, 40, "../../../res/hud/MANA_1.png", new AABBCollider(0, 0));
		ManaBar->SetPosition(Disc->GetPosition().x + 85, Disc->GetPosition().y - 5, 0, 0);
	}
	if (mana_stack = 2 && ManaBar != nullptr)
	{
		ManaBar->Destroy();
		ManaBar = scene->CreateSprite<Entity>(286, 40, "../../../res/hud/MANA_2.png", new AABBCollider(0, 0));
		ManaBar->SetPosition(Disc->GetPosition().x + 85, Disc->GetPosition().y - 5, 0, 0);
	}
	if (mana_stack = 3 && ManaBar != nullptr)
	{
		ManaBar->Destroy();
		ManaBar = scene->CreateSprite<Entity>(286, 40, "../../../res/hud/MANA_3.png", new AABBCollider(0, 0));
		ManaBar->SetPosition(Disc->GetPosition().x + 85, Disc->GetPosition().y - 5, 0, 0);
	}
	if (mana_stack = 4 && ManaBar != nullptr)
	{
		ManaBar->Destroy();
		ManaBar = scene->CreateSprite<Entity>(286, 40, "../../../res/hud/MANA_4.png", new AABBCollider(0, 0));
		ManaBar->SetPosition(Disc->GetPosition().x + 85, Disc->GetPosition().y - 5, 0, 0);
	}
	if (mana_stack = 5 && ManaBar != nullptr)
	{
		ManaBar->Destroy();
		ManaBar = scene->CreateSprite<Entity>(286, 40, "../../../res/hud/MANA_5.png", new AABBCollider(0, 0));
		ManaBar->SetPosition(Disc->GetPosition().x + 85, Disc->GetPosition().y - 5, 0, 0);
	}
	if (mana_stack = 6 && ManaBar != nullptr)
	{
		ManaBar->Destroy();
		ManaBar = scene->CreateSprite<Entity>(286, 40, "../../../res/hud/MANA_6.png", new AABBCollider(0, 0));
		ManaBar->SetPosition(Disc->GetPosition().x + 85, Disc->GetPosition().y - 5, 0, 0);
	}
	if (mana_stack = 7 && ManaBar != nullptr)
	{
		ManaBar->Destroy();
		ManaBar = scene->CreateSprite<Entity>(286, 40, "../../../res/hud/MANA_7.png", new AABBCollider(0, 0));
		ManaBar->SetPosition(Disc->GetPosition().x + 85, Disc->GetPosition().y - 5, 0, 0);
	}
	if (mana_stack = 8 && ManaBar != nullptr)
	{
		ManaBar->Destroy();
		ManaBar = scene->CreateSprite<Entity>(286, 40, "../../../res/hud/MANA_FULL.png", new AABBCollider(0, 0));
		ManaBar->SetPosition(Disc->GetPosition().x + 85, Disc->GetPosition().y - 5, 0, 0);
	}


}