#include "AABBCollider.h"
#include "CircleCollider.h"

bool AABBCollider::IsColliding(Collider* pOther)
{
    // AABB vs AABB Collision
    if (AABBCollider* otherAABB = dynamic_cast<AABBCollider*>(pOther))
    {
        // X
        bool IsPastLeftEdge = mXMax > otherAABB->mXMin;
        bool IsBeforeRightEdge = mXMin < otherAABB->mXMax;

        // Y
        bool IsPastUpperEdge = mYMax > otherAABB->mYMin;
        bool IsBeforeBottomEdge = mYMin < otherAABB->mYMax;

        if (IsPastLeftEdge && IsBeforeRightEdge && IsPastUpperEdge && IsBeforeBottomEdge)
            return true;

        
        return false;
    }

    // AABB vs Circle Collision
    if (CircleCollider* otherCircle = dynamic_cast<CircleCollider*>(pOther))
    {
        float testX = otherCircle->mX;
        float testY = otherCircle->mY;

        if (otherCircle->mX < mXMin)
            testX = mXMin;
        else if (otherCircle->mX > mXMax)
            testX = mXMax;

        if (otherCircle->mY < mYMin)
            testY = mYMin;
        else if (otherCircle->mY > mYMax)
            testY = mYMax;

        sf::Vector2f distanceVector = sf::Vector2f(otherCircle->mX, otherCircle->mY) - sf::Vector2f(testX, testY);

        float distance = (distanceVector.x * distanceVector.x) + (distanceVector.y * distanceVector.y);

        return distance < otherCircle->mRadius;
    }

    return false;
}

void AABBCollider::SetPosition(float x, float y, float anchorX, float anchorY)
{
    mXMin = x - mWidth * anchorX;
    mXMax = x + mWidth - mWidth * anchorX;

    mYMin = y - mHeight * anchorY;
    mYMax = y + mHeight - mHeight * anchorY;
}

sf::Vector2f AABBCollider::GetPosition(float anchorX, float anchorY)
{
    return sf::Vector2f(mXMin + anchorX * mWidth, mYMin + anchorY * mHeight);
}

void AABBCollider::Move(sf::Vector2f translation)
{
    mXMin += translation.x;
    mXMax += translation.x;

    mYMin += translation.y;
    mYMax += translation.y;
}