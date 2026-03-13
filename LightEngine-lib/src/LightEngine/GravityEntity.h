#pragma once
#include "Entity.h"

class GravityEntity : public Entity
{
protected:
	float mGravityStrength = 9.81f;
	float mYVelocity = 0;

public:
	void Update() override;
	void Jump();

	void SetGravityStrength(float gravityStrength) { mGravityStrength = gravityStrength; }
};

