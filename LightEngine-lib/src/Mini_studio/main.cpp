#include "pch.h"
#include "main.h"

void OnInitialize(){
	enemies enemy;
	enemy.createEnemy(100,100,50);
}

void OnEvent(const sf::Event& event){
	enemies enemy;
}

void OnUpdate(){
	enemies enemy;
	if (enemy.pEntity != nullptr)
	{
		sf::Vector2f position = enemy.pEntity->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Red);
	}
}

int main()
{
#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
#endif
	OnInitialize();
	//OnEvent();
	OnUpdate();
	return 0;
}