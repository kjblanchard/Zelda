#include "pch.h"
#include "components/BoxColliderComponent.h"
#include "core/GameLevel.h"
#include "core/GameObject.h"
#include "graphics/SpriteBatch.h"
#include "core/World.h"
#include "collision/Collision.h"
#include "core/Configuration.h"

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

		_xSizeOffset =  (Configuration::BaseConfigurationSettings.TileWidth - _colliderBox.w) /2;
		_ySizeOffset = (SG::Configuration::BaseConfigurationSettings.TileHeight - _colliderBox.h) /2;

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
		switch (typeToCheckAgainst)
		{

		case GameObjectTypes::Default: break;
		case GameObjectTypes::Tile: break;
		case GameObjectTypes::SolidTile: break;
		case GameObjectTypes::Player: break;
		case GameObjectTypes::Enemy:
			auto collisions = gameLevelToCheck->ReturnAllCollisions(_colliderBox, SG::GameObjectTypes::Enemy);
			_currentFrameCollisions.insert(std::end(_currentFrameCollisions), std::begin(collisions), std::end(collisions));
			break;
		}

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
