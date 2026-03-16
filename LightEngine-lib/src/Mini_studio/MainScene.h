#pragma once
#include "Scene.h"
#include "Player.h"

class Level;

class MainScene : public Scene
{
public:
	enum ObjectType
	{
		Enemy1,
		Enemy2,
		Enemy3,
		Enemy4,
		Boss,
		Platform,
		DestructiblePlatform,
		Ground,
		Wall
	};
private :
	Player* m_Player;
	Entity* pEntity4;

	std::vector<Entity*> mEnemies;

	Level* m_Level;

	bool MoveRight = false;


public :
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;

	void Spawn(ObjectType objectType, float levelX, float levelY);

	void OnUpdate() override;
};