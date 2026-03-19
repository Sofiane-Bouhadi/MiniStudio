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

void Parallaxe::GetPlayer(MainScene* AScene)
{
	player = AScene->GetPlayer();
}

void Parallaxe::OnUpdate()
{
	sf::Vector2f pos = GetPlayerPos();

	GoToDirection((int)pos.x, (int)pos.y, player->GetSpeed() - 20.0f);

	//pos.x += (int)movement.y / gap; // TODO Remplacer par les bons noms de variable

	if (pos.x >= ActualScene->GetWindowWidth())
	{
		pos.x -= ActualScene->GetWindowWidth();
	}

	if (pos.x < 0)
	{
		pos.x += ActualScene->GetWindowWidth();
	}
}

void Parallaxe::OnDestroy()
{
}

