#include <fstream>
#include <iostream>

#include "json.hpp"
#include "AnimatedSprite.h"

class GameManager;

using json = nlohmann::json;

vector<const char*>& AnimatedSprite::GetSources()
{
	return sources;
}

void AnimatedSprite::DecodeJson()
{
	for (int i = 0; i < sources.size(); i++)
	{
		std::ifstream f(sources[i]);

		json data = json::parse(f);

		int spriteWidth = data["frame_size"]["width"];
		int spriteHeight = data["frame_size"]["height"];

		auto array = data["animations"].array();

		for (int i = 0; i < array.size(); i++)
		{
			SpriteAnimation s;

			sf::Texture* t = new sf::Texture();
			bool success = t->loadFromFile(data["image_source"]);

			if (success == false)
			{
				std::cerr << "Image failed to load";
			}

			s.Textures = t;

			s.frameWidth = spriteWidth;
			s.frameHeight = spriteHeight;
			s.line = i * spriteHeight;
			s.column = 0;

			auto array2 = data["animations"][i]["frames"].array();

			for (int j = 0; j < array2.size(); j++)
			{
				s.Delays.push_back((int)data["animations"][i]["frames"][j]["duration"] * (int)data["animations"][i]["speed_multiplier"]);
			}

			s.isLoop = (bool)data["animations"][i]["loop"];

			s.sprite = animSprite;

			Animations.push_back(s);
		}
	}
}


void AnimatedSprite::PlayAnimation(int newIndex)
{
	//Animations[newIndex].Start();

	//m_currentIndex = newIndex;
}

void AnimatedSprite::Update()
{
	//Animations[m_currentIndex].Update();
}

void AnimatedSprite::SetSprite(sf::Sprite* s)
{
	animSprite = s;
}