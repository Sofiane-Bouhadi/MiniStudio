#pragma once
#include <vector>
#include "SpriteAnimation.h"

using namespace std;

class AnimatedSprite : public SpriteAnimation
{
	private:
		vector<SpriteAnimation> Animations;
		const char* name = "examplename";

	public:
		void DecodeJson();
};

