#pragma once
#include <SFML/Graphics/View.hpp>

class Camera
{
private:
	sf::View* mView;

public:
	sf::View* GetView();
	void SetPosition(const sf::Vector2f& pos);
	void Zoom(float factor);

	void Resize(const sf::Vector2f& size);
	void IncreaseSize(const sf::Vector2f& increasingValue);
};

