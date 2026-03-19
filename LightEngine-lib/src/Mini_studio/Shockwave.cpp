#include "Shockwave.h"
#include "Scene.h"
#include "MainScene.h"
//#include "ennemi.h" à compléter avec le bon nom de fichier


void Shockwave::OnInitialize()
{
    SetRigidBody(false);
    SetStatic(true);

    ApplyEffects();
    Destroy();
}

void Shockwave::ApplyEffects()
{
    MainScene* scene;

    sf::Vector2f origin = GetPosition(0.5f, 0.5f);

    const auto& ennemies = scene->GetEnnemyList(); //à remplacer avec le bon nom de fonction

    for (ennemi* ennemy : ennemies)
    {
        if (ennemy == nullptr || ennemy->ToDestroy()) //erreur à cause de la classe ennemi i thought
            continue;

        sf::Vector2f toEnemy = ennemy->GetPosition(0.5f, 0.5f) - origin;
        float sqDist = toEnemy.x * toEnemy.x + toEnemy.y * toEnemy.y;

        sf::CircleShape shape(m_radius);
        shape.setFillColor(sf::Color(100, 250, 80));

        if (sqDist <= m_radius * m_radius)
        {
            ennemy->TakeDamage(m_damage);
            ennemy->SetStun(m_stunTime);   
        }
    }
}

void Shockwave::OnUpdate()
{
}

void Shockwave::OnDestroy()
{
}