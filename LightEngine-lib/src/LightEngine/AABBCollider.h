#pragma once
#include "Collider.h"

class AABBCollider :
    public Collider
{
public:
    float mXMin = 0;
    float mYMin = 0;

    float mXMax = 0;
    float mYMax = 0;

    float mWidth;
    float mHeight;

    AABBCollider(float width, float height) :
        mWidth(width), mHeight(height) {}

    bool IsColliding(Collider* pOther) override;

    void SetPosition(float x, float y) override;
    sf::Vector2f GetPosition() { return sf::Vector2f(mXMin, mYMin); }

    void Move(sf::Vector2f translation) override;
};