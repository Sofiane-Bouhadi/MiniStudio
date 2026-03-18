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
		// Go on the top of the screen
		GoToPosition(mUpperX, mUpperY);
		if (mTarget.isSet == false)
		{
			// if on top of the screen go to a random side (right / left)
			if (rand() % 2 == 1)
				SetPosition(mLeftSideX, mLeftSideY);
			else
				SetPosition(mRightSideX, mRightSideY);
			mAtkStep++;
		}
		break;
	case 1:
		// Wait 0.5 seconds
		mWaitTimer = 0.5f;
		if (mWaitTimer == 0.f)
		{
			mAtkStep++;
			mTarget.isSet = true;
		}
		break;
	case 2:
		// Dash to the other side
		if (mTarget.isSet == false)
		{
			SetSpeed(mBaseSpeed);
			mAtkStep++;
			break;
		}

		SetSpeed(mAccelerationSpeed);

		if (GetPosition().x == mLeftSideX)
			GoToPosition(mRightSideX, 100);
		else
			GoToPosition(mLeftSideX, 100);
		break;
	case 3:
		// Wait 2 seconds
		mWaitTimer = 0.5f;
		if (mWaitTimer == 0.f)
		{
			mAtkStep++;
			mTarget.isSet = true;
		}
		break;
	case 4:
		// Go to center of the scene
		if (mTarget.isSet == false)
		{
			mAtkStep++;
		}
		else
			GoToPosition(mCenterX, mCenterY);
		break;
	case 5:
		// Wait 2 seconds
		mWaitTimer = 1.f;
		if (mWaitTimer == 0.f)
			mAtkStep++;
		break;
	case 6:
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
		//Wait 1 second then choose a random number of projectile
		mWaitTimer = 1.f;
		if (mWaitTimer == 0.f)
		{
			mProjectileNb = rand() % 5 + 5;
			mAtkStep++;
		}
		break;
	case 1:
		//Shoot projectiles
		if (mWaitTimer <= 0.f)
		{
			//CreateSprite<Projectile>();
			mWaitTimer = 0.2f;
			mProjectileNb -= 1;
		}
		
		if (mProjectileNb <= 0)
			mAtkStep++;
		break;
	case 2:
		//Wait 1 second
		mWaitTimer = 1.f;
		if (mWaitTimer == 0.f)
			mAtkStep++;
		break;
	case 3:
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
		GoToPosition(mCenterX, mCenterY);

		if (mTarget.isSet == false)
		{

		}
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

void Boss::OnCollision(Entity* pOther, CollidingSide collidingSide)
{
	//Projectile* collidingProjectile = dynamic_cast<Projectile*> (pOther)

	//if (collidingProjectile == nullptr)
	//	return;

	//if (collidingProjectile->GetOwnerTag() == 3) // TODO Compare if it's a projectile of the boss (for the moment the tag of the boss is 3 as shown in the condition)
	//	return;

	mHp -= 1; // TODO Change with the attack of pOther
}
