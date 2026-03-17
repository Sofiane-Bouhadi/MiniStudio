#include "Player.h"
#include "AABBCollider.h"
#include "Shoot.h"

void Player::DashRight(float deltatime)
{
    if (!CanDash)
        return;

    SetDirection(1, 0, m_DashSpeed);
    CanDash = false;
    dashCooldownTimer = 0.f;
}

void Player::DashLeft(float deltatime)
{
    if (!CanDash)
        return;

    SetDirection(-1, 0, m_DashSpeed);
    CanDash = false;
    dashCooldownTimer = 0.f;
}

void Player::MoveRight(float deltatime)
{
    mSpeed += m_acceleration * deltatime;
    if (mSpeed > m_MaxSpeed)
        mSpeed = m_MaxSpeed;

    SetDirection(1, 0, mSpeed);
    IsRight = true;
    IsLeft = false;
}

void Player::MoveLeft(float deltatime)
{
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
    Attack_Cooldown = AttackDuration;
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

void Player::OnUpdate()
{
    float dt = GetDeltaTime();

    if (!CanDash)
    {
        m_dashdela += dt;
        if (dashCooldownTimer >= m_DashDelay)
        {
            CanDash = true;
            dashCooldownTimer = 0.f;
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
