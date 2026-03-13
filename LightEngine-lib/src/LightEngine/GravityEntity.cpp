#pragma once
#include "GravityEntity.h"

void GravityEntity::Update()
{
	Entity::Update();

	mYVelocity += mGravityStrength * GetDeltaTime(); //Pensez à utiliser un Fixed DeltaTime 
	SetDirection(0, 1, mYVelocity);
}