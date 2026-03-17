#include "pch.h"
#include "main.h"

#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "MainScene.h"

#include <cstdlib>
#include <crtdbg.h>


int main()
{
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif

	GameManager* pInstance = GameManager::Get();

	pInstance->CreateWindow(1280, 720, "MainScene", 60, sf::Color::Black);

	pInstance->LaunchScene<MainScene>();

	return 0;
}
