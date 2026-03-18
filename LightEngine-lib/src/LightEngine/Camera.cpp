#include <iostream>

#include "Camera.h"
#include "Entity.h"

/*
Camera::Camera(const sf::Vector2f& size)
{
	mView = new sf::View(sf::Vector2f(size.x / 2, size.y / 2), size);
}

Camera::~Camera()
{
	delete mView;
}
*/

class Player;

void Camera::Update()
{
	if (mFollowingEntity == nullptr)
		return;

	if (followType == 0)
	{
		return;
	}

	else if (followType == 1)
	{
		SetPosition(mFollowingEntity->GetPosition());
	}

	else if (followType == 2)
	{
		//SetPosition(mFollowingEntity->GetPosition());
		//SetDirection(mFollowingEntity->GetPosition().x, mFollowingEntity->GetPosition().y, 100000);
		//this->GoToDirection(mFollowingEntity->GetPosition().x, mFollowingEntity->GetPosition().y, 100);

		std::cout << "Type 2" << std::endl;
	}
}

void Camera::SetView(const sf::Vector2f& size)
{
	mView = new sf::View(sf::Vector2f(size.x / 2, size.y / 2), size);
}

sf::View* Camera::GetView()
{
	return mView;
}

Entity* Camera::GetFollowingEntity()
{
	return mFollowingEntity;
}

void Camera::SetPosition (const sf::Vector2f& pos)
{
	mView->setCenter(pos);

}

void Camera::SetType(int type)
{
	followType = type;
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