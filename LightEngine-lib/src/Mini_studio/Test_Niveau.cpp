#pragma once
#include "Test_Niveau.h"

void Test::FillRectangle()
{
	pEntity0 = CreateRectangle<Entity>(1280, 50, sf::Color::White, new AABBCollider(1280, 50));
	pEntity0->SetPosition(1280 / 2, 720);
	pEntity0->SetRigidBody(true);
	pEntity0->SetStatic(true);

	pEntity1 = CreateRectangle<Entity>(1280, 50, sf::Color::White, new AABBCollider(1280, 50));
	pEntity1->SetPosition(1280 / 2, 720);
	pEntity1->SetRigidBody(true);
	pEntity1->SetStatic(true);

	pEntity2 = CreateRectangle<Entity>(1280, 50, sf::Color::White, new AABBCollider(1280, 50));
	pEntity2->SetPosition(1280 / 2, 720);
	pEntity2->SetRigidBody(true);
	pEntity2->SetStatic(true);

	pEntity3 = CreateRectangle<Entity>(1280, 50, sf::Color::White, new AABBCollider(1280, 50));
	pEntity3->SetPosition(1280 / 2, 720);
	pEntity3->SetRigidBody(true);
	pEntity3->SetStatic(true);

	pEntity4 = CreateRectangle<Entity>(1280, 50, sf::Color::White, new AABBCollider(1280, 50));
	pEntity4->SetPosition(1280 / 2, 720);
	pEntity4->SetRigidBody(true);
	pEntity4->SetStatic(true);
}

void Test::OnInitialize()
{

}

void Test::OnUpdate()
{

}
