#pragma once
#include "GravityEntity.h"

void GravityEntity::UpdateVelocity()
{
	mYVelocity += mGravityStrength * GetDeltaTime();
	SetDirection(0, 1, mYVelocity);
}

void GravityEntity::OnCollision(Entity* e)
{
	if (GetCollider()->CollidingSide(e->GetCollider()) == "Up")
	{
		mYVelocity = 0;
	}

	if (GetCollider()->CollidingSide(e->GetCollider()) == "Down")
	{
		mYVelocity = 0;
	}
}