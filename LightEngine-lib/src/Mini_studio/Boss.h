#pragma once
#include "Entity.h"

#include <functional>

class Boss : 
	public Entity
{
	int mAtkStep = -1;

	int mHp = 20;

	// Ces variables sont à changer selon la scène une fois qu'elle sera faite.
	float mUpperY = -720;

	float mCenterX = 0;
	float mCenterY = 360;

	float mLeftSideX = -1280;
	float mLeftSideY = 520;

	float mRightSideX = 1280;
	float mRightSideY = 520;

	float mBaseSpeed = 300.f;
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