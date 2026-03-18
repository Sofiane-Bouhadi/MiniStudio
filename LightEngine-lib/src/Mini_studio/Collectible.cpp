#include "Collectible.h"
#include "Player.h"


void Collectible::OnCollision(Entity* pOther, CollidingSide side)
{
	if (mIsCollected)
		return;
	if (side == Bottom);
	Player* player = dynamic_cast<Player*>(pOther);
	if (player) {

		Collect(player);
	}
}




void Collectible::Collect(Player* player)
{
	if(mIsCollected)	
		return;
	mIsCollected = true;
	Destroy();
}

void Collectible::OnDestroy()
{
}
