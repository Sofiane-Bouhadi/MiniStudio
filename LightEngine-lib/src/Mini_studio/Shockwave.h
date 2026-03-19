#pragma once
#include "Skill.h"
#include "enemies.h"

class enemies;

class Shockwave : public Skill
{
private:

    float m_radius = 150.f;
    int   m_damage = 20;
    float m_stunTime = 2.0f;

public:

    float GetRadius() { return m_radius; };
    void SetRadius(float r) { m_radius = r; };
    int GetDamage() { return m_damage; };
    void SetDamage(int dmg) { m_damage = dmg; };
    float GetStunTime() { return m_stunTime; };
    void SetStunTime(float s) { m_stunTime = s; };

    void ApplyEffects();

    void OnInitialize()override;
    void OnUpdate()override;
    void OnDestroy()override;

};