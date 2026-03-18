#pragma once
#include "Scene.h"
#include "Player.h"

class Level;

class MainScene : public Scene
{
public:
	enum ObjectType
	{
		//////Enemies//////
		Enemy1,
		Enemy2,
		Enemy3,
		Enemy4,
		Boss,

		//////CEILINGS//////
		JazzCeiling1,
		JazzCeiling2,

		MetalCeiling1,
		MetalCeiling2,

		//////WALLS//////
		JazzWall1,
		JazzWall2,

		HubWall1,
		HubWall2,

		MetalWall1,
		MetalWall2,

		//////GROUNDS//////
		JazzGround1,
		JazzGround2,
		JazzGroundCorner,
		JazzToHubGround1,
		JazzToHubGround2,

		HubGround,

		MetalGround1,
		MetalGround2,

		//////PLATFORMS//////
		JazzUpperLeftPlatform,
		JazzUpperMiddlePlatform,
		JazzUpperRightPlatform,
		JazzBottomLeftPlatform,
		JazzBottomMiddlePlatform,
		JazzBottomRightPlatform,

		MetalLeftPlatform,
		MetalMiddlePlatform1,
		MetalMiddlePlatform2,
		MetalRightPlatform,

		//////DestructiblePlatforms//////
		DestructiblePlatform,

		Count
	};
private :
	Player* m_Player;
	Entity* pEntity4;

	std::vector<Entity*> mEnemies;

	Level* m_Level;

	bool MoveRight = false;

	struct SpawnDesc 
	{
		const char* path;
		bool isStatic;
	};

	SpawnDesc tilePath[(int)ObjectType::Count];

public :
	Player* GetPlayer() { return m_Player; };

	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;

	void Spawn(ObjectType objectType, float levelX, float levelY);
	void SpawnCollider(float x, float y, float width, float height);

	void OnUpdate() override;
};