#pragma once
#include "Entity.h"

class GravityEntity : public Entity
{
	private:
		bool isOnGround = true;
		float gravity_strength;
		float y_velocity;

	public:
		void UpdateVelocity();
		void OnCollision(Entity* e) override;

		GravityEntity(float g_s, float y_v);
};

