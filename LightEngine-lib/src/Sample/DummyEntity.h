#pragma once
#include "Entity.h"

class DummyEntity : public GravityEntity
{
public:
	void OnCollision(GravityEntity* other) override;
};

