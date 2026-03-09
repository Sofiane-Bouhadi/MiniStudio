#include "CircleCollider.h"
#include "AABBCollider.h"

bool CircleCollider::IsColliding(Collider* pOther)
{
    //Circle vs Circle Collision
	if (CircleCollider* otherCircle = dynamic_cast<CircleCollider*> (pOther))
	{
		sf::Vector2f thisOtherVector = sf::Vector2f(mX, mY) - sf::Vector2f(otherCircle->mX, otherCircle->mY);


	}

    //Circle vs AABB collision
	if (AABBCollider* otherAABB = dynamic_cast<AABBCollider*>(pOther))
	{
		float testX = mX;
		float testY = mY;

		if (mX < otherAABB->mXMin)
			testX = otherAABB->mXMin;
		else if (mX > otherAABB->mXMax)
			testX = otherAABB->mXMax;

		if (mY < otherAABB->mYMin)
			testY = otherAABB->mYMin;
		else if (mY > otherAABB->mYMax)
			testY = otherAABB->mYMax;

		sf::Vector2f distanceVector = sf::Vector2f(mX, mY) - sf::Vector2f(testX, testY);

		float distance = (distanceVector.x * distanceVector.x) + (distanceVector.y * distanceVector.y);

		return distance < mRadius;
	}

    return false;
}

#include <iostream>

void CircleCollider::SetPosition(float x, float y)
{
	mX = x;
	mY = y;
}

void CircleCollider::Move(sf::Vector2f translation)
{
	mX += translation.x;
	mY += translation.y;
}
