#pragma once
#include "Entity.h"

class Player;

class Collectible : public Entity
{
private:
    bool mIsCollected = false;

public:
    Collectible() = default;

    void OnCollision(Entity* pOther, CollidingSide side) override;

    void Collect(Player* player);
	void OnDestroy() override;
};
