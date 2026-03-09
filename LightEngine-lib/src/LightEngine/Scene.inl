	#pragma once

#include "Scene.h"
#include "GameManager.h"
#include "Entity.h"


template<typename T>
T* Scene::CreateEntity(float width, float height, sf::Shape* shape, const sf::Color& color, Collider* collider)
{
	static_assert(std::is_base_of<Entity, T>::value, "T must be derived from Entity");

	T* newEntity = new T();

	Entity* entity = newEntity;
	entity->Initialize(width, height, shape, color, collider);
	
	mpGameManager->mEntitiesToAdd.push_back(newEntity);

	return newEntity;
}
