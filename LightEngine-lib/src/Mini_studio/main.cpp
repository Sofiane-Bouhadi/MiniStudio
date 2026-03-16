#include "pch.h"
#include "main.h"





int main()
{
	sceneTemporaire scene;
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif
	GameManager* pInstance = GameManager::Get();

	pInstance->CreateWindow(1280, 720, "Scene", 60, sf::Color::Black);

	pInstance->LaunchScene<sceneTemporaire>();

	return 0;
}