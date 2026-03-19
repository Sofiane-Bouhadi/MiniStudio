#pragma once
#include "Scene.h"
#include "Player.h"
#include "Parallaxe.h"

class Level;
#include "enemies.h"
#include "IA_Enemies.h"

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
		Wall1,
		Wall2,
		Wall3,
		Ground1,
		Ground2,
		Ground3,
		Platform,
		DestructiblePlatform,
	};
private :
	Player* m_Player;
	Entity* pEntity4;

	Parallaxe* mParallaxFar = nullptr;
	Parallaxe* mParallaxMid = nullptr;
	Parallaxe* mParallaxNear = nullptr;
	Parallaxe* mParallaxClose = nullptr;

	std::vector<enemies*> mEnemies;

	Level* m_Level;

	enemies* enemy1;
	enemies* enemy2;
	enemies* enemy3;
	enemies* enemy4;
	bool MoveRight = false;

	/*true = position 1; false = position 2*/
	bool Enemove = true; 

	StateMachine* state;
	IA* ia;
	bool fall_attack = false;
	bool smart_attack = false;

public :
	Player* GetPlayer() { return m_Player; }

	std::vector<enemies*> GetEnnemyList() { return mEnemies; }

	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;

	void Spawn(ObjectType objectType, float levelX, float levelY);
	void SpawnCollider(float x, float y, float width, float height);

	void OnUpdate() override;
};