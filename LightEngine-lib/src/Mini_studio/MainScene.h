#pragma once
#include "Scene.h"
#include "Player.h"
#include "enemies.h"
#include "IA_Enemies.h"

class MainScene : public Scene
{
private :

	Player* m_Player;
	Entity* pEntity4;
	enemies* enemy1;
	enemies* enemy2;
	bool MoveRight = false;
	StateMachine* state;
	IA* ia;
	bool fall_attack = false;
	bool smart_attack = false;

public :
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;

	void OnUpdate() override;
};