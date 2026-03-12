#include "DummyEntity.h"
#include "AABBCollider.h"

#include <iostream>

void DummyEntity::OnCollision(Entity* other)
{
	std::cout << "Collision detected." << std::endl;
}