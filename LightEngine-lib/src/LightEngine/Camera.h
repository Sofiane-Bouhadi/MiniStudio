#pragma once

#include "Entity.h"
#include <SFML/Graphics/View.hpp>


class Camera : public Entity
{
private:
	sf::View* mView = nullptr;

	bool mFollow = false;
	Entity* mFollowingEntity = nullptr;

	int followType = 1;

public:
	void Update();

	void SetView(const sf::Vector2f& size);
	sf::View* GetView();

	bool IsFollowing() { return mFollow; }
	Entity* GetFollowingEntity();

	void SetPosition(const sf::Vector2f& pos);
	void SetFollowingEntity(Entity* entity) { mFollowingEntity = entity; }
	void SetFollow(bool follow) { mFollow = follow; }
	void SetType(int type);

	void Zoom(float factor);

	void Resize(const sf::Vector2f& size);
	void IncreaseSize(const sf::Vector2f& increasingValue);
};

