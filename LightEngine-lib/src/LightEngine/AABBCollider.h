#pragma once
#include "Collider.h"

class AABBCollider :
    public Collider
{
public:
    float mXMin;
    float mYMin;

    float mXMax;
    float mYMax;

    bool IsColliding(Collider* pOther) override;

};

