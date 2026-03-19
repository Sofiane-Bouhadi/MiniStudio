#pragma once
#include <vector>
#include "SpriteAnimation.h"

using namespace std;

class AnimatedSprite
{
	private:
		vector<SpriteAnimation> Animations;
		vector<const char*> sources;

		int m_currentIndex;

		sf::Sprite* animSprite;

	public:
		vector<const char*>& GetSources();
		void DecodeJson();
		void PlayAnimation(int n);
		void SetSprite(sf::Sprite* s);

		void Update();

};