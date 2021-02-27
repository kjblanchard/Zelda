#include "pch.h"
#include "components/BoxColliderComponent.h"
#include "GameLevel.h"
#include "GameObject.h"
#include "SpriteBatch.h"
#include "World.h"
#include "collision/Collision.h"

namespace SG
{
	BoxColliderComponent::BoxColliderComponent(GameObject* _gameObject, SDL_Rect offsetAndSize, bool debugMode) :
		Component(_gameObject, SGComponentTypes::BoxCollider), _colliderBox(offsetAndSize),
		_shouldDrawDebugBox(debugMode)
	{
	}

	void BoxColliderComponent::Startup()
	{
		_xOffset = _colliderBox.x;
		_yOffset = _colliderBox.y;

		//TODO change the 32's to a var in the configuration file
		_xSizeOffset =  (32 - _colliderBox.w) /2;
		_ySizeOffset = (32 - _colliderBox.h) /2;

		_colliderBox.x = _gameObject->Location().X + _xOffset + _xSizeOffset;
		_colliderBox.y = _gameObject->Location().Y + _yOffset + _ySizeOffset;

	}

	void BoxColliderComponent::Update(const double& deltaTime)
	{
		_colliderBox.x = _gameObject->Location().X + _xOffset + _xSizeOffset;
		_colliderBox.y = _gameObject->Location().Y + _yOffset + _ySizeOffset;
		_previousFrameCollisions = _currentFrameCollisions;
		_currentFrameCollisions.clear();
	}

	void BoxColliderComponent::Draw(SpriteBatch& spriteBatch)
	{
		if (SG::World::_isCollisionDebug && _shouldDrawDebugBox)
			spriteBatch.AddToSpriteBatch(&_colliderBox);
	}

	bool BoxColliderComponent::IsCollision(const SDL_Rect& otherCollider) const
	{
		return Collision::DoShapesIntersect(&_colliderBox, &otherCollider);
	}

	void BoxColliderComponent::GatherAllCurrentIntersections(SG::GameLevel* gameLevelToCheck,
		SG::GameObjectTypes typeToCheckAgainst)
	{
		auto collisions = gameLevelToCheck->ReturnAllCollisions(_colliderBox, SG::GameObjectTypes::SolidTile);
		_currentFrameCollisions.insert(std::end(_currentFrameCollisions), std::begin(collisions), std::end(collisions));

	}

	void BoxColliderComponent::CallFunctionOnEachJustIntersected(std::function<void()> functionToCallOnEach)
	{
		for (auto currentFrameCollision : _currentFrameCollisions)
		{
			if (CheckIfJustIntersected(currentFrameCollision->Id))
				functionToCallOnEach();
		}
	}

	bool BoxColliderComponent::CheckIfJustIntersected(int gameObjectId)
	{
		bool returnAnswer = false;
		for (auto currentFrameCollision : _currentFrameCollisions)
		{
			if (currentFrameCollision->Id == gameObjectId)
				returnAnswer = true;
		}
		if (returnAnswer)
		{
			for (auto previousFrameCollision : _previousFrameCollisions)
			{
				if (previousFrameCollision->Id == gameObjectId)
					returnAnswer = false;
			}
		}
		return returnAnswer;
	}
}
