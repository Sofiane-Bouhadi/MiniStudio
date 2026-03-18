#include <iostream>
#include "GameManager.h"
#include "Camera.h"
#include "GravityEntity.h"
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
		sf::Vector2f pos = mFollowingEntity->GetPosition();

		
		GravityEntity* g = (GravityEntity*)mFollowingEntity;

		float YVelocity = g->GetYVelocity();

		if (YVelocity > GetScene()->GetWindowHeight() * 0.8)
		{
			YVelocity = GetScene()->GetWindowHeight() * 0.8;
		}

		if (YVelocity < - GetScene()->GetWindowHeight() * 0.8)
		{
			YVelocity = - GetScene()->GetWindowHeight() * 0.8;
		}

		GoToPosition(pos.x, pos.y + g->GetYVelocity(), 300);

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


void Camera::SetFollowingEntity(Entity* entity) 
{ 
	mFollowingEntity = entity;
	SetPosition(mFollowingEntity->GetPosition());
}

void Camera::SetPosition (const sf::Vector2f& pos)
{
	Entity::SetPosition(pos.x, pos.y, 0.5f, 0.5f);
	mView->setCenter(pos);
}

void Camera::OnSetPosition(float x, float y)
{
	float halfHeight = GetScene()->GetWindowHeight() / 2;
	float halfWidth = GetScene()->GetWindowWidth() / 2;
	mView->setCenter(x + halfWidth, y + halfHeight);
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