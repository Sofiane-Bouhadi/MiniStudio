#pragma once
#include "Entity.h"

#include <functional>

class Boss : 
	public Entity
{
	int mAtkStep = -1;

	int mHp = 20;

	// Ces variables sont à changer selon la scène une fois qu'elle sera faite.
	float mUpperX = 250;
	float mUpperY = 250;

	float mCenterX = 500;
	float mCenterY = 650;

	float mLeftSideX = 0;
	float mLeftSideY = 100;

	float mRightSideX = 1000;
	float mRightSideY = 100;

	float mBaseSpeed = 500.f;
	float mAccelerationSpeed = 1500.f;

	float mWaitTimer = 0.f;

	float mProjectileNb = 0.f;

	//

	std::function<void()> mFunction;

	void OnInitialize() override;
	void OnUpdate() override;

	void LaunchAtk();

	void DashAtk();
	void ProjectileAtk();
	void ShockwaveAtk();
	void HealAtk();

	void OnCollision(Entity* pOther, CollidingSide collidingSide) override;
};