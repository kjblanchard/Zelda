#include "pch.h"

#include "components/BoxColliderComponent.h"

#include "GameObject.h"
#include "SpriteBatch.h"
#include "World.h"
#include "collision/Collision.h"

namespace SG
{
	BoxColliderComponent::BoxColliderComponent(GameObject* _gameObject) : Component(_gameObject, SGComponentTypes::BoxCollider)
	{
	}

	void BoxColliderComponent::Startup()
	{
		ColliderBox = SDL_Rect{ _gameObject->Location().X,_gameObject->Location().Y,32,32 };
	}

	void BoxColliderComponent::Update(const double& deltaTime)
	{
		ColliderBox.x = _gameObject->Location().X;
		ColliderBox.y = _gameObject->Location().Y;
	}

	void BoxColliderComponent::Draw(SpriteBatch& spriteBatch)
	{
		if (SG::World::_isCollisionDebug)
			spriteBatch.AddToSpriteBatch(&ColliderBox);
	}

	bool BoxColliderComponent::IsCollision(const SDL_Rect& otherCollider)
	{
		return Collision::DoShapesIntersect(ColliderBox, otherCollider);
	}

	bool BoxColliderComponent::IsCollision(const SDL_Rect& potentialMoveRect, const SDL_Rect& otherCollider)
	{
		return Collision::DoShapesIntersect(potentialMoveRect, otherCollider);
	}
}
