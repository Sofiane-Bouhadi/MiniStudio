#pragma once
#include "Scene.h"
#include "Player.h"


class MainScene : public Scene
{
private :

	Player* m_Player;

	bool MoveRight = false;


public :
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;

	void OnUpdate() override;
};