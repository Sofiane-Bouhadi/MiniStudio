#include "GravityEntity.h"

GravityEntity::GravityEntity(float g_s)
{
	gravity_strength = g_s;
}

void GravityEntity::UpdateVelocity()
{
	y_velocity += gravity_strength * GetDeltaTime();
	SetDirection(0, 1, y_velocity);
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
	}
}