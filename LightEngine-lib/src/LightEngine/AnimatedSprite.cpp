#include <fstream>

#include "json.hpp"
#include "AnimatedSprite.h"

using json = nlohmann::json;

void AnimatedSprite::DecodeJson()
{
	std::ifstream f(name);

	json data = json::parse(f);

	int spriteWidth = data["frame_size"]["width"];
	int spriteHeight = data["frame_size"]["height"];

	auto array = data["animations"].array();

	for (int i = 0; i < array.size(); i++)
	{
		SpriteAnimation s;

		auto array2 = data["animations"][i]["frames"].array();

		for (int j = 0; j < array2.size(); j++)
		{
			sf::Texture t;

			// donner la texture

			s.Textures.push_back(t);

			s.Delays.push_back((int)data["animations"][i]["frames"][j]["duration"] * (int)data["animations"][i]["speed_multiplier"]);
		}

		s.isLoop = (bool)data["animations"][i]["loop"];
	}
}