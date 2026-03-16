#include "Level.h"
#include "GameManager.h"
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

void Level::ReadLevel()
{
	for (int i = 0; i < mLevel.size(); ++i)
	{
		for (int j = 0; j < mLevel[i].size(); ++j)
		{
			switch (mLevel[i][j])
			{
			case '_':
				std::cout << "Platform" << std::endl;
				break;
			case 'X':
				std::cout << "Enemy" << std::endl;
				break;
			case 'Y':
				std::cout << "Ground" << std::endl;
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