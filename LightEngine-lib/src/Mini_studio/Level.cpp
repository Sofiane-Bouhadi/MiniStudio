#include "Level.h"
#include "GameManager.h"
#include "MainScene.h"
#include <iostream>
#include <fstream>

/*void Level::Update(sf::Vector2f playerPos)
{
	if (playerPos.x != mCurrentCol)
	{
		if (playerPos.x < _level[0].size())
		{
			ReadLevel();
			if (playerPos.x > mCurrentCol)
				mCurrentCol += 1;
			else
				mCurrentCol -= 1;
		}
	}
	else if (playerPos.y != mCurrentCol)
	{
		if (playerPos.y < _level.size())
		{
			ReadLevel();
			mCurrentLine += 1;
		}
	}
}*/

void Level::ReadLevel(MainScene* scene)
{
	for (int i = 0; i < mLevel.size(); ++i)
	{
		for (int j = 0; j < mLevel[i].size(); ++j)
		{
			switch (mLevel[i][j])
			{
			case '1':
				scene->Spawn(MainScene::Enemy1, j * mPixelPerChar, i * mPixelPerChar);
				std::cout << "Enemy 1" << std::endl;
				break;
			case '2':
				scene->Spawn(MainScene::Enemy2, j * mPixelPerChar, i * mPixelPerChar);
				std::cout << "Enemy 2" << std::endl;
				break;
			case '3':
				scene->Spawn(MainScene::Enemy3, j * mPixelPerChar, i * mPixelPerChar);
				std::cout << "Enemy 3" << std::endl;
				break;
			case '4':
				scene->Spawn(MainScene::Enemy4, j * mPixelPerChar, i * mPixelPerChar);
				std::cout << "Enemy 4" << std::endl;
				break;
			case 'B':
				scene->Spawn(MainScene::Boss, j * mPixelPerChar, i * mPixelPerChar);
				std::cout << "Boss" << std::endl;
				break;
			case 'W':
				scene->Spawn(MainScene::Wall, j * mPixelPerChar, i * mPixelPerChar);
				std::cout << "Wall" << std::endl;
				break;
			case 'G':
				scene->Spawn(MainScene::Ground, j * mPixelPerChar, i * mPixelPerChar);
				std::cout << "Ground" << std::endl;
				break;
			case '=':
				scene->Spawn(MainScene::Platform, j * mPixelPerChar, i * mPixelPerChar);
				std::cout << "Platform" << std::endl;
				break;
				// ...
			}
		}
	}
}

void Level::OpenFile()
{
	std::ifstream file(_path);

	if (file.is_open()) 
	{
		std::string line;
		while (std::getline(file, line)) 
		{
			mLevel.push_back(line);
		}
	}
	else
	{
		std::cout << "File : " << _path << " not found" << std::endl;
	}

	file.close();
}