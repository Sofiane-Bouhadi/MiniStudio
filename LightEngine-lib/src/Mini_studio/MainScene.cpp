#include "MainScene.h"
#include "Player.h"
#include "Level.h"

#include "AABBCollider.h"
#include "Utils.h"
#include "Debug.h"

#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>

void MainScene::OnInitialize()
{

    m_Player = CreateRectangle<Player>(155, 225, sf::Color::Green, new AABBCollider(155, 225));
    m_Player->SetPosition(1000, 300);
    m_Player->SetSpeed(m_Player->GetMinSpeed());
    m_Player->SetRigidBody(true);
    m_Player->SetGravityStrength(1200.f);
    m_Player->SetJumpStrength(750);

    GameManager::Get()->GetCamera()->SetFollowingEntity(m_Player);
    GameManager::Get()->GetCamera()->Zoom(2.f);

    m_Level = new Level("../../../res/Levels/levelFull.txt", this);
}

void MainScene::OnEvent(const sf::Event& event)
{
    bool jump = false;
    bool base_attack = false;
    bool shoot = false;



    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Space && m_Player->GetNbJump() > 0)
        {
            jump = true;
            m_Player->DecreaseJump();
        }
    }

    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Space)
        {
            jump = false;
        }
    }

    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Right)
            base_attack = true;
    }

    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Right)
            base_attack = false;
    }

    if (event.type == sf::Event::JoystickButtonPressed)
    {
        if (event.joystickButton.button == 0 && m_Player->GetNbJump() > 0)
        {
            jump = true;
            m_Player->DecreaseJump();
        }

        if (event.joystickButton.button == 2)
            base_attack = true;

        if (event.joystickButton.button == 3)
            shoot = true;
    }

    if (event.type == sf::Event::JoystickButtonReleased)
    {
        if (event.joystickButton.button == 0)
            jump = false;

        if (event.joystickButton.button == 2)
            base_attack = false;

        if (event.joystickButton.button == 3)
            shoot = false;
    }

    if (jump)
        m_Player->Jump();

    if (base_attack)
        m_Player->BaseAttack();

    if (shoot)
        m_Player->PlayerShoot();
}

void MainScene::OnUpdate()
{
    float dt = GetDeltaTime();

   
  /*  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || m_Player->IsDashAvailable() == true);
        {
            m_Player->DashLeft(dt);
        }
  */  
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_Player->IsDashAvailable() == true)
    { 
        m_Player->DashLeft(dt);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_Player->MoveRight(dt);
        if (!m_Player->GetAttack())
            m_Player->SetRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_Player->MoveRight(dt);
        if (!m_Player->GetAttack())
            m_Player->SetRight();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        m_Player->MoveLeft(dt);
        if (!m_Player->GetAttack())
            m_Player->SetLeft();
    }

    float axisX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);

    if (axisX > 10)
    {
        m_Player->MoveRight(dt);
        m_Player->SetRight();
        m_Player->UnsetLeft();
    }
    else if (axisX < -10)
    {
        m_Player->MoveLeft(dt);
        m_Player->SetLeft();
        m_Player->UnsetRight();
    }
}

void MainScene::Spawn(ObjectType objectType, float levelX, float levelY)
{
    Entity* e = nullptr;

    switch (objectType)
    {
    case Enemy1:
        e = CreateRectangle<Entity>(32, 32, sf::Color::Red, new AABBCollider(32, 32));
        break;

    case Enemy2:
        e = CreateRectangle<Entity>(32, 32, sf::Color::Blue, new AABBCollider(32, 32));
        break;

    case Enemy3:
        e = CreateRectangle<Entity>(32, 32, sf::Color::Yellow, new AABBCollider(32, 32));
        break;

    case Enemy4:
        e = CreateRectangle<Entity>(32, 32, sf::Color::Magenta, new AABBCollider(32, 32));
        break;

    case Boss:
        e = CreateRectangle<Entity>(64, 64, sf::Color::Cyan, new AABBCollider(64, 64));
        break;

    case DestructiblePlatform:
        e = CreateRectangle<Entity>(32, 32, sf::Color::White, new AABBCollider(32, 32));
        break;
    }

    if (e)
    {
        e->SetPosition(levelX, levelY);
        e->SetRigidBody(true);
        mEnemies.push_back(e);
    }
}

void MainScene::SpawnCollider(float x, float y, float width, float height)
{
    Entity* pEntity = CreateRectangle<Entity>(width, height, sf::Color::Transparent, new AABBCollider(width, height));
    pEntity->SetPosition(x, y, 0.f, 0.f);
    pEntity->SetRigidBody(true);
    pEntity->SetStatic(true);
}
