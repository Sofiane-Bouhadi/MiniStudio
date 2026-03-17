#pragma once
#include "Entity.h"

class Player;

class Parallaxe : public Entity
{
private:

	sf::Vector2f PLayerPos;
	Player* player;
	Scene* ActualScene;

public:

	void SetPlayerPos(Player* player);
	sf::Vector2f GetPlayerPos();

	void GetPLayer(MainScene* AScene);

	void OnUpdate()override;

	void OnDestroy()override;

};
