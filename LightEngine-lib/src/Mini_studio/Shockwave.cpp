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

    const auto& enemies = scene->GetEnnemyList(); //à remplacer avec le bon nom de fonction

    for (ennemi* enemy : enemies)
    {
        if (enemy == nullptr || enemy->ToDestroy()) //erreur à cause de la classe ennemi i thought
            continue;

        sf::Vector2f toEnemy = enemy->GetPosition(0.5f, 0.5f) - origin;
        float sqDist = toEnemy.x * toEnemy.x + toEnemy.y * toEnemy.y;

        sf::CircleShape shape(m_radius);
        shape.setFillColor(sf::Color(100, 250, 80));

        if (sqDist <= m_radius * m_radius)
        {
            enemy->TakeDamage(m_damage);
            enemy->SetStun(m_stunTime);   
        }
    }
}

void Shockwave::OnUpdate()
{
}

void Shockwave::OnDestroy()
{
}
