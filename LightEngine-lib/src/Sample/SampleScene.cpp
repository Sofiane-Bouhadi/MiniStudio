#include "SampleScene.h"
#include "GravityEntity.h"
#include "DummyEntity.h"

#include "Debug.h"

#include "CircleCollider.h"
#include "AABBCollider.h"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include <iostream>

void SampleScene::OnInitialize()
{
	// Creation of a Sprite (with a path)
	pEntity1 = CreateSprite<DummyEntity>(64, 64, "../../../res/image.png", new AABBCollider(64, 64));
	pEntity1->SetPosition(100, 100);
	pEntity1->SetRigidBody(true);

	//Circle
	pEntity2 = CreateCircle<DummyEntity>(50, sf::Color::Green, new CircleCollider(50));
	pEntity2->SetPosition(500, 500);
	pEntity2->SetRigidBody(true);

	//Circle
	pEntity3 = CreateCircle<DummyEntity>(25, sf::Color::Green, new CircleCollider(25));
	pEntity3->SetPosition(200, 300);
	pEntity3->SetRigidBody(true);

	//Rectangle
	pEntity4 = CreateRectangle<DummyEntity>(1000, 200, sf::Color::Red, new AABBCollider(1000, 200));
	pEntity4->SetPosition(1280 / 2, 700);
	pEntity4->SetRigidBody(true);
	pEntity4->SetStatic(true);

	//GravityEntity
	gEntity = CreateRectangle<GravityEntity>(50, 100, sf::Color::Blue, new AABBCollider(50, 100));
	gEntity->SetPosition(720, 0);
	gEntity->SetRigidBody(true);

	//Choose an entity to follow
	//GameManager::Get()->GetCamera()->SetFollowingEntity(gEntity);

	pEntitySelected = nullptr;
}

void SampleScene::OnEvent(const sf::Event& event)
{
	if (event.type == sf::Event::EventType::MouseButtonPressed)
	{
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

	if (event.type == sf::Event::EventType::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Y)
		{
			if (GameManager::Get()->GetCamera()->GetFollowingEntity() == nullptr)
			{
				//Camera will follow the entity1
				GameManager::Get()->GetCamera()->SetFollowingEntity(pEntity1);
			}
			else
			{
				//Camera will not follow the entity it was following
				GameManager::Get()->GetCamera()->SetFollowingEntity(nullptr);
			}
		}
	}
}

void SampleScene::TrySetSelectedEntity(DummyEntity* pEntity, int x, int y)
{
	sf::Vector2i mousePos = { x, y };

	sf::Vector2f worldPos = GameManager::Get()->mpWindow->mapPixelToCoords(mousePos);

	if (pEntity->IsInside(worldPos.x, worldPos.y) == false)
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