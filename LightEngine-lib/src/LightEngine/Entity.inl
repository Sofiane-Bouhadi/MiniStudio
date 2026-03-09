#include "Entity.h"

#include "GameManager.h"

template<typename T>
T* Entity::GetScene() const
{
	T* pScene = dynamic_cast<T*>(GetScene());

	_ASSERT(pScene != nullptr);

	return pScene;
}


template<typename T>
T* Entity::CreateEntity(float width, float height, sf::Shape* shape, const sf::Color& color, Collider* collider)
{
	return GetScene()->CreateEntity<T>(width, height, shape, color, collider);
}