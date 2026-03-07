#pragma once
#include "Collider.h"

class CircleCollider :
	public Collider
{
public:
	float mX;
	float mY;

	float mRadius;

	bool IsColliding(Collider* pOther) override;
};

