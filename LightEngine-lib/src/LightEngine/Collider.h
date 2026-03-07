#pragma once
#include <SFML/System/Vector2.hpp>

class Collider
{
public:
	virtual bool IsColliding(Collider* pOther) = 0;

	virtual void SetPosition(float x, float y) = 0;
	virtual sf::Vector2f GetPosition() = 0;

	virtual void Move(sf::Vector2f translation) = 0;
};