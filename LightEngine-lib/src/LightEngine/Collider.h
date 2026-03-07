#pragma once
#include <SFML/System/Vector2.hpp>

class Collider
{
public:
	virtual bool IsColliding(Collider* pOther) = 0;
};

