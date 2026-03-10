#include "DummyEntity.h"
#include "AABBCollider.h"

#include <iostream>

void DummyEntity::OnCollision(Entity* other)
{
	if (dynamic_cast<AABBCollider*> (GetCollider()))
		std::cout << ((AABBCollider*)GetCollider())->CollidingSide(other->GetCollider()) << std::endl;
}