#pragma once
#include "Collider.h"

class CircleCollider :
	public Collider
{
public:
	float mX = 0;
	float mY = 0;

	float mRadius;

	CircleCollider(float radius) :
		mRadius(radius) {}

	bool IsColliding(Collider* pOther) override;

	void SetPosition(float x, float y) override;
	sf::Vector2f GetPosition() { return sf::Vector2f(mX, mY); }

	void Move(sf::Vector2f translation) override;
};