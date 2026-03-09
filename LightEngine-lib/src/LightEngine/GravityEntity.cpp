#include "GravityEntity.h"

void GravityEntity::UpdateVelocity()
{
	y_velocity -= gravity_strength * GetDeltaTime();
}

void GravityEntity::OnCollision(Entity* e)
{
	/* if(GetCollider()->CollisionType(e) == "down")
	* {
		
	  }
	
	
	*/
}
