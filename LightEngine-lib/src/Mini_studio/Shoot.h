#pragma once
#include "skill.h"

class Shoot : public Skill
{
private:

public:

	void OnInitialize()override;
	void OnUpdate()override;
	void OnDestroy()override;

};
