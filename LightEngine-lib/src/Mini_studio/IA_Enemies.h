#include "StateMachine.h"
#include "enemies.h"

#pragma once
class IA
{
private:

protected:

public:
	enum typesEn {
		Fall,
		smart,

		count
	};

	void liveBull(enemies* pEnemy);

	void liveFall(enemies* pEnemy);

	void livePunch(enemies* pEnemy);

	void liveShot(enemies* pEnemy);

};

