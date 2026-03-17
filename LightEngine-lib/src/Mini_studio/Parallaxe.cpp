#pragma once
#include "Parallaxe.h"
#include "Player.h"
#include "MainScene.h"

void Parallaxe::SetPlayerPos(Player* player)
{
	PLayerPos = player->GetPosition();
}

sf::Vector2f Parallaxe::GetPlayerPos()
{
	return PLayerPos;
}

void Parallaxe::GetPLayer(MainScene* ActuScene)
{
	player = ActuScene->GetPlayer();
}

void Parallaxe::OnInitialize()
{
}

void Parallaxe::OnUpdate()
{
	sf::Vector2f pos = GetPlayerPos();
	GoToDirection((int)pos.x, (int)pos.y, player->GetSpeed());
}

void Parallaxe::OnDestroy()
{
}

