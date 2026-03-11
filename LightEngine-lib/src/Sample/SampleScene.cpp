#include "SampleScene.h"
#include "GravityEntity.h"
#include "DummyEntity.h"

#include "Debug.h"

#include "CircleCollider.h"
#include "AABBCollider.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <iostream>

void SampleScene::OnInitialize()
{
	pEntity1 = CreateEntity<DummyEntity>(100, 100, new sf::RectangleShape, sf::Color::Red, new AABBCollider(100, 100));
	pEntity1->SetPosition(100, 100);
	pEntity1->SetRigidBody(false);

	pEntity2 = CreateEntity<DummyEntity>(75, 75, new sf::CircleShape, sf::Color::Cyan, new CircleCollider(37.5f));
	pEntity2->SetPosition(500, 500);
	pEntity2->SetRigidBody(true);

	pEntity3 = CreateEntity<DummyEntity>(50, 50, new sf::CircleShape, sf::Color::Green, new CircleCollider(25));
	pEntity3->SetPosition(200, 300);
	pEntity3->SetRigidBody(true);

	pEntity4 = CreateEntity<DummyEntity>(50, 50, new sf::RectangleShape, sf::Color::Yellow, new AABBCollider(50, 50));
	pEntity4->SetPosition(700, 100);
	pEntity4->SetRigidBody(true);

	pEntitySelected = nullptr;
}

void SampleScene::OnEvent(const sf::Event& event)
{
	if (event.type != sf::Event::EventType::MouseButtonPressed)
		return;

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		TrySetSelectedEntity(pEntity1, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pEntity2, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pEntity3, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedEntity(pEntity4, event.mouseButton.x, event.mouseButton.y);
	}

	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (pEntitySelected != nullptr) 
		{
			pEntitySelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.f);
		}
	}
}

void SampleScene::TrySetSelectedEntity(DummyEntity* pEntity, int x, int y)
{
	if (pEntity->IsInside(x, y) == false)
		return;

	pEntitySelected = pEntity;
}

void SampleScene::OnUpdate()
{
	if(pEntitySelected != nullptr)
	{
		sf::Vector2f position = pEntitySelected->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::Blue);
	}
}