#pragma once
#include "../Sample/SampleScene.h"

class attack
{
private:
protected:
	attack* pAttack;
	int m_width { 0 };
	int m_height { 0 };
	float m_x { 0 };
	float m_y { 0 };
	float m_movingX { 0 };
	float m_movingY { 0 };
public:
	/*3 parties : taille, position initial, vecteur de deplacement*/
	attack(int width, int height, float x, float y, float movingX, float movingY)
		: m_width(width), m_height(height), m_x(x), m_y(y),  m_movingX(movingX), m_movingY(movingY)
	{}
};

