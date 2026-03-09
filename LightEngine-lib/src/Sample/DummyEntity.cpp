#include "DummyEntity.h"

#include <iostream>

void DummyEntity::OnCollision(Entity* other)
{
	std::cout << "DummyEntity Collision detected." << std::endl;
}