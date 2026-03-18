#include "Boss.h"
//#include "Projectile.h"

void Boss::OnUpdate()
{
	mWaitTimer -= GetDeltaTime();

	if (mHp <= 0)
		Destroy();

	mFunction();
}

void Boss::LaunchAtk()
{
	int randomAtk = rand() % 4;

	switch (randomAtk)
	{
	case 1:
		mFunction = std::bind(&Boss::DashAtk, this);
		break;
	case 2:
		mFunction = std::bind(&Boss::ProjectileAtk, this);
		break;
	case 3:
		mFunction = std::bind(&Boss::ShockwaveAtk, this);
		break;
	case 4:
		mFunction = std::bind(&Boss::HealAtk, this);
		break;
	}

	mAtkStep = 0;
	mFunction();
}

void Boss::DashAtk() 
{
	switch (mAtkStep) 
	{
	case 0:
		mTarget.isSet = true;
		break;
	case 1:
		// Go on the top of the screen
		if (mTarget.isSet == false)
		{
			// if on top of the screen go to a random side (right / left)
			if (rand() % 2 == 1)
				SetPosition(mLeftSideX, mLeftSideY);
			else
				SetPosition(mRightSideX, mRightSideY);
			mAtkStep++;
			mWaitTimer = 0.5f;
		}
		else
		{
			GoToPosition(mUpperX, mUpperY);
		}

		break;
	case 2:
		// Wait 0.5 seconds
		if (mWaitTimer <= 0.f)
		{
			mAtkStep++;
			mTarget.isSet = true;
		}
		break;
	case 3:
		// Dash to the other side
		if (mTarget.isSet == false)
		{
			SetSpeed(mBaseSpeed);
			mAtkStep++;
			mWaitTimer = 0.5f;
			break;
		}

		SetSpeed(mAccelerationSpeed);

		if (GetPosition().x == mLeftSideX)
			GoToPosition(mRightSideX, 100);
		else
			GoToPosition(mLeftSideX, 100);
		break;
	case 4:
		// Wait 2 seconds
		if (mWaitTimer <= 0.f)
		{
			mAtkStep++;
			mTarget.isSet = true;
		}
		break;
	case 5:
		// Go to center of the scene
		if (mTarget.isSet == false)
		{
			mAtkStep++;
			mWaitTimer = 1.f;
		}
		else
			GoToPosition(mCenterX, mCenterY);
		break;
	case 6:
		// Wait 1 second
		if (mWaitTimer <= 0.f)
			mAtkStep++;
		break;
	case 7:
		//Change Atk
		LaunchAtk();
		break;
	}
}

void Boss::ProjectileAtk()
{
	switch (mAtkStep)
	{
	case 0:
		mWaitTimer = 1.f;
		mAtkStep++;
		break;
	case 1:
		//Wait 1 second then choose a random number of projectile
		if (mWaitTimer <= 0.f)
		{
			mProjectileNb = rand() % 5 + 5;
			mAtkStep++;
		}
		break;
	case 2:
		//Shoot projectiles
		if (mWaitTimer <= 0.f)
		{
			//CreateSprite<Projectile>();
			mWaitTimer = 0.2f;
			mProjectileNb -= 1;
		}
		
		if (mProjectileNb <= 0)
		{
			mWaitTimer = 1.f;
			mAtkStep++;
		}
		break;
	case 3:
		//Wait 1 second
		if (mWaitTimer <= 0.f)
			mAtkStep++;
		break;
	case 4:
		//Change Atk
		LaunchAtk();
		break;
	}
}

void Boss::ShockwaveAtk()
{
	switch (mAtkStep)
	{
	case 0:

		break;
	case 1:

		break;
	case 2:

		break;
	case 3:
		LaunchAtk();
		break;
	}
}

void Boss::HealAtk()
{
	switch (mAtkStep)
	{
	case 0:
		mHp += 2;
		mAtkStep++;
		//Add some things like repeat it and wait between heals
		mWaitTimer = 0.5f;
		break;
	case 1:
		if (mWaitTimer <= 0.f)
			mAtkStep++;
		break;
	case 3:
		LaunchAtk();
		break;
	}
}

void Boss::OnCollision(Entity* pOther, CollidingSide collidingSide)
{
	//Projectile* collidingProjectile = dynamic_cast<Projectile*> (pOther)

	//if (collidingProjectile == nullptr)
	//	return;

	//if (collidingProjectile->GetOwnerTag() == 3) // TODO Compare if it's a projectile of the boss (for the moment the tag of the boss is 3 as shown in the condition)
	//	return;

	mHp -= 1; // TODO Change with the attack of pOther
}
