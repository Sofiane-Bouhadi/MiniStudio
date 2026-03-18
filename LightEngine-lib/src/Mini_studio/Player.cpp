#include "Player.h"
#include "AABBCollider.h"
#include "Charm.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

Player::~Player()
{
	for (Charm* charm : mCharms)
	{
		delete charm;
	}
	mCharms.clear();
}

void Player::DashRight(float deltatime)
{
	if (!CanDash)
		return;

	mIsDashing = true;
	m_dashTimer = 0.f;
	SetDirection(1, 0, static_cast<float>(m_DashSpeed));
	CanDash = false;
	m_dashCooldownTimer = 0.f;
}

void Player::DashLeft(float deltatime)
{
	if (!CanDash)
		return;

	mIsDashing = true;
	m_dashTimer = 0.f;
	SetDirection(-1, 0, static_cast<float>(m_DashSpeed));
	CanDash = false;
	m_dashCooldownTimer = 0.f;
}

void Player::MoveRight(float deltatime)
{
	if (mIsDashing) return;

	mSpeed += m_acceleration * deltatime;
	if (mSpeed > m_MaxSpeed)
		mSpeed = m_MaxSpeed;

	SetDirection(1, 0, mSpeed);
	IsRight = true;
	IsLeft = false;
}

void Player::MoveLeft(float deltatime)
{
	if (mIsDashing) return;

	mSpeed += m_acceleration * deltatime;
	if (mSpeed > m_MaxSpeed)
		mSpeed = m_MaxSpeed;

	SetDirection(-1, 0, mSpeed);
	IsLeft = true;
	IsRight = false;
}

void Player::BaseAttack()
{
	if (Attack_Cooldown > 0)
		return;

	IsAttack = true;
	Attack_Cooldown = 1.0f;
}

void Player::PlayerShoot()
{
	if (shoot != nullptr)
		shoot->Fire(PlayerTag, GetPosition());
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

	if (m_life <= 0)
		IsAlive = false;

	if (m_life < 0)
		m_life = 0;
}

void Player::RestoreHealth(int amount)
{
	m_life += amount;

	if (m_life > m_maxLife)
		m_life = m_maxLife;
}

bool Player::GetAttack()
{
	return IsAttack;
}

void Player::OnInitialize()
{
	Scene* scene = GetScene();

	attack = scene->CreateRectangle<Entity>(85, 30, sf::Color::Red, new AABBCollider(85, 30));
	attack->SetPosition(-9999, -9999);
}

void Player::AddCharm(Charm* charm)
{
	if (!charm) return;

	mCharms.push_back(charm);
	mCurrentCharmIndex = static_cast<int>(mCharms.size()) - 1;
	this->EquipCurrentCharm();
}

void Player::EquipCharm(int index)
{
	if (index < 0 || index >= static_cast<int>(mCharms.size()))
		return;

	if (mEquippedCharm)
		mEquippedCharm->OnUnequip(this);

	mEquippedCharm = mCharms[index];

	if (mEquippedCharm)
		mEquippedCharm->OnEquip(this);

	mCurrentCharmIndex = index;
}

void Player::EquipCurrentCharm()
{
	if (mCurrentCharmIndex >= 0 && mCurrentCharmIndex < static_cast<int>(mCharms.size()))
		EquipCharm(mCurrentCharmIndex);
}

void Player::UnequipCharm()
{
	if (mEquippedCharm)
	{
		mEquippedCharm->OnUnequip(this);
		mEquippedCharm = nullptr;
	}
}

void Player::CycleCharm()
{
	if (mCharms.empty())
		return;

	mCurrentCharmIndex = (mCurrentCharmIndex + 1) % static_cast<int>(mCharms.size());
	EquipCharm(mCurrentCharmIndex);
}

void Player::OnUpdate()
{
	float dt = GetDeltaTime();

	if (mIsDashing)
	{
		m_dashTimer += dt;

		if (m_dashTimer >= m_DashDuration)
		{
			mIsDashing = false;
			mSpeed = m_MinSpeed;
			SetDirection(0, 0, mSpeed);
		}
	}

	if (!CanDash)
	{
		m_dashCooldownTimer += dt;

		if (m_dashCooldownTimer >= m_DashDelay)
		{
			CanDash = true;
			m_dashCooldownTimer = 0.f;
		}
	}

	if (IsAttack)
	{
		Attack_Cooldown -= dt;

		if (IsRight)
			attack->SetPosition(GetPosition().x + 115, GetPosition().y);
		else if (IsLeft)
			attack->SetPosition(GetPosition().x - 115, GetPosition().y);

		if (Attack_Cooldown <= 0)
		{
			IsAttack = false;
			attack->SetPosition(-9999, -9999);
		}
	}

	if (m_life <= 0)
		IsAlive = false;

}

void Player::SetRight()
{
	IsRight = true;
	IsLeft = false;
	//  régler la du sprite aussi !

}

void Player::SetLeft()
{
	IsLeft = true;
	IsRight = false;
	
}