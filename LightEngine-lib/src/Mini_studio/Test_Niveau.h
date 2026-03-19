#pragma once
#include "Scene.h"
#include "AABBCollider.h"
#include <vector>


class Test : public Scene
{
private:

	Entity* pEntity0;
	Entity* pEntity1;
	Entity* pEntity2;
	Entity* pEntity3;
	Entity* pEntity4;

	std::vector<Entity*> block;

public:

	void FillRectangle();

	void OnInitialize() override;

	void OnUpdate() override;

};


