#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "ExampleScene.h"

#include <cstdlib>
#ifdef _WIN32
#include <crtdbg.h>
#endif

int main()
{
	GameManager* pInstance = GameManager::Get();

	pInstance->CreateWindow(1280, 720, "Example Scene - Enemies & Platforms", 60, sf::Color(30, 30, 50));

	pInstance->LaunchScene<ExampleScene>();

	return 0;
}