#pragma once

#include "Scene.h"

class Player;
class SimpleEnemy;

class ExampleScene : public Scene
{
private:
	Player* mPlayer = nullptr;

	SimpleEnemy* mEnemy1 = nullptr;
	SimpleEnemy* mEnemy2 = nullptr;
	SimpleEnemy* mEnemy3 = nullptr;

	Entity* mGround = nullptr;
	Entity* mPlatform1 = nullptr;
	Entity* mPlatform2 = nullptr;
	Entity* mPlatform3 = nullptr;
	Entity* mWallLeft = nullptr;
	Entity* mWallRight = nullptr;

	bool mMoveRight = false;
	bool mMoveLeft = false;

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;
};
