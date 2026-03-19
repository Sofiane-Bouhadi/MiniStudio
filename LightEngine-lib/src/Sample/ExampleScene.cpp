#include "ExampleScene.h"
#include "Player.h"
#include "SimpleEnemy.h"
#include "Camera.h"
#include "AABBCollider.h"
#include "Debug.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

void ExampleScene::OnInitialize()
{
	// ===== GROUND =====
	mGround = CreateRectangle<Entity>(2000, 50, sf::Color::White, new AABBCollider(2000, 50));
	mGround->SetPosition(0, 650, 0.f, 0.f);
	mGround->SetStatic(true);
	mGround->SetRigidBody(true);

	// ===== PLATFORMS =====
	// Platform 1 (low, left side)
	mPlatform1 = CreateRectangle<Entity>(250, 20, sf::Color(150, 150, 150), new AABBCollider(250, 20));
	mPlatform1->SetPosition(200, 530, 0.f, 0.f);
	mPlatform1->SetStatic(true);
	mPlatform1->SetRigidBody(true);

	// Platform 2 (medium height, center)
	mPlatform2 = CreateRectangle<Entity>(300, 20, sf::Color(150, 150, 150), new AABBCollider(300, 20));
	mPlatform2->SetPosition(550, 420, 0.f, 0.f);
	mPlatform2->SetStatic(true);
	mPlatform2->SetRigidBody(true);

	// Platform 3 (high, right side)
	mPlatform3 = CreateRectangle<Entity>(200, 20, sf::Color(150, 150, 150), new AABBCollider(200, 20));
	mPlatform3->SetPosition(900, 310, 0.f, 0.f);
	mPlatform3->SetStatic(true);
	mPlatform3->SetRigidBody(true);

	// ===== WALLS =====
	mWallLeft = CreateRectangle<Entity>(30, 720, sf::Color(100, 100, 100), new AABBCollider(30, 720));
	mWallLeft->SetPosition(0, 0, 0.f, 0.f);
	mWallLeft->SetStatic(true);
	mWallLeft->SetRigidBody(true);

	mWallRight = CreateRectangle<Entity>(30, 720, sf::Color(100, 100, 100), new AABBCollider(30, 720));
	mWallRight->SetPosition(1250, 0, 0.f, 0.f);
	mWallRight->SetStatic(true);
	mWallRight->SetRigidBody(true);

	// ===== PLAYER =====
	mPlayer = CreateRectangle<Player>(40, 60, sf::Color::Green, new AABBCollider(40, 60));
	mPlayer->SetPosition(100, 500);
	mPlayer->SetRigidBody(true);
	mPlayer->SetGravityStrength(600.f);
	mPlayer->SetJumpStrength(350.f);

	// Camera follows the player
	GameManager::Get()->GetCamera()->SetFollowingEntity(mPlayer);

	// ===== ENEMIES =====
	// Enemy 1: patrols on the ground (red)
	mEnemy1 = CreateRectangle<SimpleEnemy>(50, 50, sf::Color::Red, new AABBCollider(50, 50));
	mEnemy1->SetPosition(400, 600);
	mEnemy1->SetPatrolRange(300.f, 600.f);
	mEnemy1->SetPatrolSpeed(80.f);

	// Enemy 2: patrols on platform 2 (orange)
	mEnemy2 = CreateRectangle<SimpleEnemy>(40, 40, sf::Color(255, 140, 0), new AABBCollider(40, 40));
	mEnemy2->SetPosition(600, 380);
	mEnemy2->SetPatrolRange(550.f, 830.f);
	mEnemy2->SetPatrolSpeed(60.f);

	// Enemy 3: patrols on platform 3 (magenta)
	mEnemy3 = CreateRectangle<SimpleEnemy>(35, 35, sf::Color::Magenta, new AABBCollider(35, 35));
	mEnemy3->SetPosition(920, 275);
	mEnemy3->SetPatrolRange(900.f, 1080.f);
	mEnemy3->SetPatrolSpeed(100.f);

	std::cout << "=== Example Scene Initialized ===" << std::endl;
	std::cout << "Controls:" << std::endl;
	std::cout << "  D / Right Arrow : Move right" << std::endl;
	std::cout << "  Q / Left Arrow  : Move left" << std::endl;
	std::cout << "  Space           : Jump" << std::endl;
	std::cout << "=================================" << std::endl;
}

void ExampleScene::OnEvent(const sf::Event& event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Space)
		{
			mPlayer->Jump();
		}
	}
}

void ExampleScene::OnUpdate()
{
	// Continuous movement with keyboard polling
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		mPlayer->SetDirection(1, 0, 200.f);
		mPlayer->SetSpeed(200.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		mPlayer->SetDirection(-1, 0, 200.f);
		mPlayer->SetSpeed(200.f);
	}
	else
	{
		mPlayer->SetSpeed(0.f);
		mPlayer->SetDirection(0, 0, 0.f);
	}

	// Draw HUD info
	Debug::DrawText(10.f, 30.f, "Player pos: " + std::to_string((int)mPlayer->GetPosition().x) + ", " + std::to_string((int)mPlayer->GetPosition().y), sf::Color::Yellow);
}
