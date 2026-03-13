#pragma once
#include "GravityEntity.h"

void GravityEntity::Update()
{
	Entity::Update();

	mYVelocity += mGravityStrength * GetDeltaTime();
	SetDirection(0, 1, mYVelocity);
}