#include "SpriteAnimation.h"


void SpriteAnimation::Start()
{
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
	timeRemaining -= GameManager::Get()->GetDeltaTime();

	if (timeRemaining < 0)
	{
		if (frame < Delays.size())
		{
			frame++;
		}
		else if (frame == Delays.size() and isLoop == true)
		{
			frame = 0;
		}

		else if (frame == Delays.size() and isLoop == false)
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