#include "pch.h"
#include "main.h"





int main()
{
	sceneTemporaire scene;
	bool running = true;
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif
	scene.OnInitialize();
	while (running == true)
	{
		//scene.OnEvent();
		scene.OnUpdate();
	}

	return 0;
}