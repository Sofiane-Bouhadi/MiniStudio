#include "Camera.h"

sf::View* Camera::GetView()
{
	return mView;
}

void Camera::SetPosition(const sf::Vector2f& pos)
{
	mView->setCenter(pos);
}

void Camera::Zoom(float factor)
{
	mView->zoom(factor);
}

void Camera::Resize(const sf::Vector2f& size)
{
	mView->setSize(size);
}

void Camera::IncreaseSize(const sf::Vector2f& increasingValue)
{
	mView->setSize(mView->getSize() + increasingValue);
}