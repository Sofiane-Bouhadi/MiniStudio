#include "Projectile.h"
#include <cmath>


#define M_PI 3.14159265358979323846

void Projectile::OnInitialize()
{
    SetRigidBody(false);
    SetStatic(false);
    SetSpeed(m_speed);
}

void Projectile::SetTarget(float x, float y)
{
    m_targetPos = { x, y };
    m_hasTarget = true;

    sf::Vector2f pos = GetPosition(0.5f, 0.5f);
    float dx = x - pos.x;
    float dy = y - pos.y;

    float len = std::sqrt(dx * dx + dy * dy);
    if (len > 0.f)
    {
        dx /= len;
        dy /= len;
    }

    SetDirection(dx, dy, m_speed);
    RotateTowardDirection(dx, dy);
}

void Projectile::SetDirectionAndRotate(float dx, float dy)
{
    float len = std::sqrt(dx * dx + dy * dy);
    if (len > 0.f) { dx /= len; dy /= len; }

    SetDirection(dx, dy, m_speed);
    RotateTowardDirection(dx, dy);
}

void Projectile::RotateTowardDirection(float dx, float dy)
{
    float angleRad = std::atan2(dy, dx);
    float angleDeg = angleRad * (180.f / static_cast<float>(M_PI));

    sf::Shape* shape = GetShape();
    if (shape)
    {
        shape->setOrigin(mWidth * 0.5f, mHeight * 0.5f);
        shape->setRotation(angleDeg);
    }
}

void Projectile::OnCollision(Entity* pOther, CollidingSide collidingSide)
{
    if (!pOther->IsTag(m_ownerTag)) 
    {
        Destroy();
    }
    
}

void Projectile::OnUpdate()
{
    sf::Vector2f cameraCenter = GameManager::Get()->GetCamera()->GetView()->getCenter();
    sf::Vector2f cameraSize = GameManager::Get()->GetCamera()->GetView()->getSize();

    sf::Vector2f pos = GetPosition(0.5f, 0.5f);
    float negative_camX = cameraCenter.x - cameraSize.x;
    float positive_camX = cameraCenter.x + cameraSize.x;
    float negative_camY = cameraCenter.y - cameraSize.y;
    float positive_camY = cameraCenter.y + cameraSize.y;
    if (pos.x <  negative_camX || pos.x > positive_camX || pos.y < negative_camY || pos.y > positive_camY) // à changer si besoin
    {
        Destroy();
    }
   
    
    
}

void Projectile::OnDestroy()
{
}