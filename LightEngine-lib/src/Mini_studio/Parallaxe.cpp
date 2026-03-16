#pragma once
#include "Parallaxe.h"
#include "Player.h"
#include "MainScene.h"

void Paralax::SetPlayerPos(Player* player)
{
	PLayerPos = player->GetPosition();
}

sf::Vector2f Paralax::GetPlayerPos()
{
	return PLayerPos;
}

void Paralax::GetPLayer(MainScene* ActuScene)
{
	player = ActuScene->GetPlayer();
}

void Paralax::OnInitialize()
{
}

void Paralax::OnUpdate()
{
	sf::Vector2f pos = GetPlayerPos();
	GoToDirection(pos.x, pos.y, player->GetSpeed());
}

void Paralax::OnDestroy()
{
}

