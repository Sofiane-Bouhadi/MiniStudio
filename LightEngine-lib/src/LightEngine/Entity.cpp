#include "Entity.h"

#include "GameManager.h"
#include "AssetManager.h"
#include "Utils.h"
#include "Debug.h"
#include "AABBCollider.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

void Entity::Initialize(float width, float height, sf::RectangleShape* shape, const sf::Color& color, Collider* collider)
{
	mDirection = sf::Vector2f(0.0f, 0.0f);

	mDrawable = shape;
	mTransformable = shape;

	mTransformable->setOrigin(0.f, 0.f);
	((sf::Shape*)mDrawable)->setFillColor(color);

	((sf::RectangleShape*)mTransformable)->setSize(sf::Vector2f(width, height));

	mWidth = width;
	mHeight = height;
	
	mCollider = collider;
	
	mTarget.isSet = false;

	OnInitialize();
}

void Entity::Initialize(float radius, sf::CircleShape* shape, const sf::Color& color, Collider* collider)
{
	mDirection = sf::Vector2f(0.0f, 0.0f);

	mDrawable = shape;
	mTransformable = shape;

	mTransformable->setOrigin(0.f, 0.f);
	((sf::Shape*)mDrawable)->setFillColor(color);

	((sf::CircleShape*)mTransformable)->setRadius(radius / 2);

	mWidth = radius * 2;
	mHeight = radius * 2;
	
	mCollider = collider;
	
	mTarget.isSet = false;

	OnInitialize();
}

void Entity::Initialize(float width, float height, const char* texturePath, Collider* collider)
{
	mDirection = sf::Vector2f(0.0f, 0.0f);

	sf::Sprite* sprite = new sf::Sprite(*AssetManager::Get()->GetTexture(texturePath, width, height));

	mDrawable = sprite;
	mTransformable = sprite;
	
	mWidth = width;
	mHeight = height;
	mCollider = collider;
	
	mTarget.isSet = false;

	OnInitialize();
}

void Entity::Repulse(Entity* other) 
{
	sf::Vector2f distance = GetPosition(0.5f, 0.5f) - other->GetPosition(0.5f, 0.5f);
	
	float sqrLength = (distance.x * distance.x) + (distance.y * distance.y);
	float length = std::sqrt(sqrLength);

	float radius1 = GetRadius();
	float radius2 = other->GetRadius();

	float overlap = (length - (radius1 + radius2)) * 0.5f;

	sf::Vector2f normal = distance / length;

	sf::Vector2f translation = overlap * normal;

	sf::Vector2f position1 = GetPosition(0.5f, 0.5f) - translation;
	sf::Vector2f position2 = other->GetPosition(0.5f, 0.5f) + translation;

	SetPosition(position1.x, position1.y, 0.5f, 0.5f);
	other->SetPosition(position2.x, position2.y, 0.5f, 0.5f);
}

bool Entity::IsColliding(Entity* other) const 
{
	if (mCollider == nullptr || other->mCollider == nullptr)
	{
		return false;
	}

	return mCollider->IsColliding(other->GetCollider());
}

bool Entity::IsInside(float x, float y) const
{
	sf::Vector2f position = GetPosition(0.5f, 0.5f);

	float dx = x - position.x;
	float dy = y - position.y;

	float radius = GetRadius();

	return (dx * dx + dy * dy) < (radius * radius);
}

void Entity::Destroy()
{
	mToDestroy = true;

	delete mCollider;

	delete mDrawable;
	delete mTransformable;

	OnDestroy();
}

void Entity::SetPosition(float x, float y, float ratioX, float ratioY)
{
	float size = GetRadius() * 2;

	x -= size * ratioX;
	y -= size * ratioY;

	mTransformable->setPosition(sf::Vector2f(x, y));

	sf::Vector2f currentPosition = GetPosition(0.5f, 0.5f);
	mCollider->SetPosition(currentPosition.x, currentPosition.y);

	//#TODO Optimise
	if (mTarget.isSet) 
	{
		sf::Vector2f position = GetPosition(0.5f, 0.5f);
		mTarget.distance = Utils::GetDistance(position.x, position.y, mTarget.position.x, mTarget.position.y);
		GoToDirection(mTarget.position.x, mTarget.position.y);
		mTarget.isSet = true;
	}
}


sf::Vector2f Entity::GetPosition(float ratioX, float ratioY) const
{
	float size = GetRadius() * 2;

	sf::Vector2f position;

	position = mTransformable->getPosition();

	position.x += size * ratioX;
	position.y += size * ratioY;

	return position;
}

sf::Shape* Entity::GetShape()
{
	if (dynamic_cast<sf::CircleShape*> (mDrawable) != nullptr)
	{
		return ((sf::CircleShape*)mDrawable);
	}
	else if (dynamic_cast<sf::RectangleShape*> (mDrawable) != nullptr)
	{
		return ((sf::RectangleShape*)mDrawable);
	}
}

bool Entity::GoToDirection(int x, int y, float speed)
{
	sf::Vector2f position = GetPosition(0.5f, 0.5f);
	sf::Vector2f direction = sf::Vector2f(x - position.x, y - position.y);
	
	bool success = Utils::Normalize(direction);
	if (success == false)
		return false;

	SetDirection(direction.x, direction.y, speed);

	return true;
}

bool Entity::GoToPosition(int x, int y, float speed)
{
	if (GoToDirection(x, y, speed) == false)
		return false;

	sf::Vector2f position = GetPosition(0.5f, 0.5f);

	mTarget.position = { x, y };
	mTarget.distance = Utils::GetDistance(position.x, position.y, x, y);
	mTarget.isSet = true;

	return true;
}


void Entity::SetDirection(float x, float y, float speed)
{
	if (speed > 0)
		mSpeed = speed;

	mDirection = sf::Vector2f(x, y);
	mTarget.isSet = false;
}

void Entity::Update()
{
	OnUpdate();
}

void Entity::FixedUpdate(float fixedDt)
{
	float dt = fixedDt;
	float distance = dt * mSpeed;
	sf::Vector2f translation = distance * mDirection;
	mTransformable->move(translation);

	sf::Vector2f currentPosition = GetPosition(0.5f, 0.5f);
	mCollider->SetPosition(currentPosition.x, currentPosition.y);


	if (mTarget.isSet)
	{
		float x1 = GetPosition(0.5f, 0.5f).x;
		float y1 = GetPosition(0.5f, 0.5f).y;

		float x2 = x1 + mDirection.x * mTarget.distance;
		float y2 = y1 + mDirection.y * mTarget.distance;

		Debug::DrawLine(x1, y1, x2, y2, sf::Color::Cyan);

		Debug::DrawCircle(mTarget.position.x, mTarget.position.y, 5.f, sf::Color::Magenta);

		mTarget.distance -= distance;

		if (mTarget.distance <= 0.f)
		{
			SetPosition(mTarget.position.x, mTarget.position.y, 0.5f, 0.5f);
			mDirection = sf::Vector2f(0.f, 0.f);
			mTarget.isSet = false;
		}
	}



}

Scene* Entity::GetScene() const
{
	return GameManager::Get()->GetScene();
}

float Entity::GetDeltaTime() const
{
	return GameManager::Get()->GetDeltaTime();
}