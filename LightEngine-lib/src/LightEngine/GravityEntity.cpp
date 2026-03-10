#include "GravityEntity.h"

GravityEntity::GravityEntity(float g_s, float y_v)
{
	gravity_strength = g_s;
	y_velocity = y_v;
}

void GravityEntity::UpdateVelocity()
{
	if (isOnGround == false)
	{
		y_velocity += gravity_strength * GetDeltaTime();
	}
}

void GravityEntity::OnCollision(Entity* e)
{
	if (GetCollider()->CollidingSide(e->GetCollider()) == "Up")
	{
		y_velocity = 0;
	}

	if (GetCollider()->CollidingSide(e->GetCollider()) == "Down")
	{
		y_velocity = 0;
		isOnGround = true;
	}
}

