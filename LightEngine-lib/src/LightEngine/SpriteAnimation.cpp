#include "SpriteAnimation.h"


void SpriteAnimation::Start()
{
	if (Delays.empty()) return;

	frame = 0;
	timeRemaining = Delays[0];

	sf::IntRect ir;

	ir.width = frameWidth;
	ir.height = frameHeight;

	ir.left = column;
	ir.top = line;

	sprite->setTexture(*Textures);
	sprite->setTextureRect(ir);
}

void SpriteAnimation::Update()
{
	if (Delays.empty()) return;

	timeRemaining -= GameManager::Get()->GetDeltaTime();

	if (timeRemaining < 0)
	{
		int lastFrame = (int)Delays.size() - 1;

		if (frame < lastFrame)
		{
			frame++;
		}
		else if (isLoop == true)
		{
			frame = 0;
		}
		else
		{
			return;
		}

		timeRemaining += Delays[frame];
		column = frameWidth * frame;

		sf::IntRect ir;

		ir.width = frameWidth;
		ir.height = frameHeight;

		ir.left = column;
		ir.top = line;

		sprite->setTextureRect(ir);
	}
}