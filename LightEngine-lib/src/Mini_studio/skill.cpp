#pragma once
#include "skill.h"

void Skill::shockwave_attack()
{
    shockwave.CreateRectangle<Entity>(180, 180, sf::Color::Transparent, new AABBCollider(180, 180));
    shockwave.SetTag(1);
}



void Skill::OnInitialize()
{
    shockwave.SetRigidBody(false);
    shockwave.SetStatic(true);

}

void Skill::OnUpdate()
{
}

void Skill::OnDestroy()
{
}