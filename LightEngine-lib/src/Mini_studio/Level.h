#pragma once
#include <vector>
#include <string>
#include <SFML/System/Vector2.hpp>

class Level
{
private:
	std::vector<std::string> mLevel = {};

	// float mCurrentTime = 0.f;
	int mCurrentCol = 1;
	int mCurrentLine = 1;

	const char* _path;

public:
	Level(const char* path) : _path(path) 
	{
		OpenFile();
	}
	~Level() {}

	//void Update(sf::Vector2f playerPos);
	void ReadLevel();
	void OpenFile();
};

