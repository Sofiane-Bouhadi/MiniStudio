#include "Shoot.h"
#include "Projectile.h"
#include "AABBCollider.h"


void Shoot::Fire(int ownerTag, sf::Vector2f facingDir)
{

    AABBCollider* collider = new AABBCollider(m_projWidth, m_projHeight);

    proj = CreateSprite<Projectile>(m_projWidth, m_projHeight, m_texturePath, collider);

    proj->SetDamage(m_damage);
    proj->SetProjectileSpeed(m_projectileSpeed);
    proj->SetOwnerTag(ownerTag);

    sf::Vector2f spawnPos = GetPosition(0.5f, 0.5f);
    proj->SetPosition(spawnPos.x, spawnPos.y, 0.5f, 0.5f);

    proj->SetDirectionAndRotate(facingDir.x, facingDir.y);

}

void Shoot::OnInitialize()
{
    Scene* scene = GetScene();
    proj = scene->CreateRectangle<Projectile>(m_projWidth, m_projHeight, sf::Color::Red, new AABBCollider(20, 10));

}

void Shoot::OnUpdate()
{
    
}

void Shoot::OnDestroy()
{
}