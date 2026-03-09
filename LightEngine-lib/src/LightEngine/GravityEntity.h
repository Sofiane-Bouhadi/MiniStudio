#pragma once
#include "Entity.h"

class GravityEntity : public Entity
{
	private:
		float gravity_strength;
		float y_velocity;

	public:
		void UpdateVelocity();
		void OnCollision(Entity* e) override;
};

