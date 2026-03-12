#pragma once
#include "Entity.h"

class GravityEntity : public Entity
{
private:
	float mGravityStrength = 9.81f;
	float mYVelocity = 0;

public:
	void UpdateVelocity();
	void OnCollision(Entity* entity, CollidingSide collidingSide) override;

	void SetGravityStrength(float gravityStrength) { mGravityStrength = gravityStrength; }
};

