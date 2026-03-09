#include "pch.h"
#include "main.h"
#include "Debug.h"
int main()
{
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif
	enemies enemies;
	enemies.createEnemy(100,100,50);
	return 0;
}
