#pragma once
#include <vector>
#include <string>
#include <SFML/System/Vector2.hpp>

class MainScene;

class Level
{
private:
	std::vector<std::string> mLevel = {};

	int mPixelPerChar = 124;

	const char* _path;

public:
	Level(const char* path, MainScene* scene) : _path(path) 
	{
		OpenFile();
		ReadLevel(scene);
	}
	~Level() {}

	//void Update(sf::Vector2f playerPos);
	void ReadLevel(MainScene* scene);
	void OpenFile();
};

