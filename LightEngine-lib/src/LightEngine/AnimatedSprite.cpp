#include <fstream>

#include "json.hpp"
#include "AnimatedSprite.h"

using json = nlohmann::json;

void AnimatedSprite::DecodeJson()
{
	std::ifstream f(name);

	json data = json::parse(f);

	int spriteWidth = data["frame_size"]["width"];
	int spriteLength = data["frame_size"]["width"];
}