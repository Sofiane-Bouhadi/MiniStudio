#include "DummyEntity.h"

#include <iostream>

void DummyEntity::OnCollision(GravityEntity* other)
{
	std::cout << "DummyEntity::OnCollision" << std::endl;
}