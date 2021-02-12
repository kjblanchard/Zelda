#include "pch.h"

#include "components/BoxColliderComponent.h"

#include "GameObject.h"
#include "SpriteBatch.h"
#include "World.h"
#include "collision/Collision.h"

namespace SG
{
	BoxColliderComponent::BoxColliderComponent(GameObject* _gameObject, SDL_Rect offsetAndSize) : Component(_gameObject, SGComponentTypes::BoxCollider)
	{
		ColliderBox = offsetAndSize;
	}

	void BoxColliderComponent::Startup()
	{
		xOffset = ColliderBox.x;
		yOffset = ColliderBox.y;

		xSizeOffset =  (32 - ColliderBox.w) /2;
		ySizeOffset = (32 - ColliderBox.h) /2;

		ColliderBox.x = _gameObject->Location().X;
		ColliderBox.y = _gameObject->Location().Y;

	}

	void BoxColliderComponent::Update(const double& deltaTime)
	{
		ColliderBox.x = _gameObject->Location().X + xOffset + xSizeOffset;
		ColliderBox.y = _gameObject->Location().Y + yOffset + ySizeOffset;
	}

	void BoxColliderComponent::Draw(SpriteBatch& spriteBatch)
	{
		if (SG::World::_isCollisionDebug)
			spriteBatch.AddToSpriteBatch(&ColliderBox);
	}

	bool BoxColliderComponent::IsCollision(const SDL_Rect& otherCollider)
	{
		return Collision::DoShapesIntersect(&ColliderBox, &otherCollider);
	}

	bool BoxColliderComponent::IsCollision(const SDL_Rect& potentialMoveRect, const SDL_Rect& otherCollider)
	{
		return Collision::DoShapesIntersect(&potentialMoveRect, &otherCollider);
	}


}
