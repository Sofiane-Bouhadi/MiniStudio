#pragma once
#include "Entity.h"

#include <functional>

class Boss : 
	public Entity
{
private:
	int mAtkStep = -1;

	int mHp = 33;
	int mHpMax = 33;

	// Ces variables sont à changer selon la scène une fois qu'elle sera faite.
	float mUpperY = -720;

	float mCenterX = 0;
	float mCenterY = 0;

	float mLeftSideX = -2100;
	float mLeftSideY = 520;

	float mRightSideX = 2100;
	float mRightSideY = 520;

	float mBaseSpeed = 600.f;
	float mAccelerationSpeed = 1400.f;

	float mWaitTimer = 0.f;
	float mInvulnerabilityTime = 0.f;

	float mProjectileNb = 0.f;

	//

	std::function<void()> mFunction;

protected:
	void OnInitialize() override;
	void OnUpdate() override;
	void OnCollision(Entity* pOther, CollidingSide collidingSide) override;

public:
	void LaunchAtk();

	void DashAtk();
	void ProjectileAtk();
	void ShockwaveAtk();
	void HealAtk();
};