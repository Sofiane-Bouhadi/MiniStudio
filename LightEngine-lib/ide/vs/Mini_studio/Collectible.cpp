#include "Collectible.h"
#include "Player.h"

void Collectible::SetOnCollect(std::function<void(Player*)> func)
{
	mOnCollect = func;
}

void Collectible::OnCollision(Entity* pOther, CollidingSide side)
{
	if (mIsCollected)
		return;

	Player* player = dynamic_cast<Player*>(pOther);

	if (player)
	{
		Collect(player);
	}
}

void Collectible::Collect(Player* player)
{
	mIsCollected = true;

	if (mOnCollect)
		mOnCollect(player);

	Destroy();
}