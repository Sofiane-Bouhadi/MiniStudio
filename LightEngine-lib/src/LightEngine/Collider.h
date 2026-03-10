#pragma once
#include <SFML/System/Vector2.hpp>

class Collider
{
public:
	virtual bool IsColliding(Collider* pOther) = 0;

	virtual void SetPosition(float x, float y, float anchorX = 0.5f, float anchorY = 0.5f) = 0;
	virtual sf::Vector2f GetPosition(float anchorX = 0.5f, float anchorY = 0.5f) = 0;

	virtual const char* CollidingSide(Collider* pOther) = 0;

	virtual void Move(sf::Vector2f translation) = 0;
};