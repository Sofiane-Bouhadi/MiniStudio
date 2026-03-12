#pragma once
#include "GravityEntity.h"

void GravityEntity::UpdateVelocity()
{
	mYVelocity += mGravityStrength * GetDeltaTime();
	SetDirection(0, 1, mYVelocity);
}

void GravityEntity::OnCollision(Entity* e, CollidingSide collidingSide)
{
	if (collidingSide == Top)
	{
		mYVelocity = 0;
	}

	if (collidingSide == Bottom)
	{
		mYVelocity = 0;
	}
}