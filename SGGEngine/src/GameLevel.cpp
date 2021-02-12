#include "pch.h"

#include "GameObjectList.h"
#include  "GameLevel.h"
#include "tilemap/TileMap.h"
#include "components/BoxColliderComponent.h"

namespace SG
{
	bool GameLevel::IsThereACollision(SDL_Rect& boxColliderToCheck, GameObjectTypes listToSearch)
	{
		switch (listToSearch)
		{
		case GameObjectTypes::Default:
			return CheckForCollisions(boxColliderToCheck, *TotalGameObjectList);
		case GameObjectTypes::SolidTile:
			return CheckForCollisions(boxColliderToCheck, *SolidLayerList);
		case GameObjectTypes::Enemy:
			return CheckForCollisions(boxColliderToCheck, *EnemiesLayerList);
		case GameObjectTypes::Player:
			return CheckForCollisions(boxColliderToCheck, *PlayerLayerList);
		default:
			return false;

		}
	}

	const GameObject& GameLevel::ReturnFirstCollisionGameObject(SDL_Rect& gameObjectChecking,
		GameObjectTypes listToSearch)
	{
		switch (listToSearch)
		{
		case GameObjectTypes::Default:
			return ReturnFirstCollisionObjectInList(gameObjectChecking, *TotalGameObjectList);
		case GameObjectTypes::SolidTile:
			return ReturnFirstCollisionObjectInList(gameObjectChecking, *SolidLayerList);
		case GameObjectTypes::Enemy:
			return ReturnFirstCollisionObjectInList(gameObjectChecking, *EnemiesLayerList);
		case GameObjectTypes::Player:
			return ReturnFirstCollisionObjectInList(gameObjectChecking, *PlayerLayerList);
		default:
			return GameObject();

		}
	}

	bool GameLevel::CheckForCollisions(SDL_Rect& rect, GameObjectList& gameObjectList)
	{
		for (auto levelGameObjectList : gameObjectList._gameObjectList)
		{
			auto component = levelGameObjectList->GetComponent<SG::BoxColliderComponent>();
			if (component)
			{
				if (component->IsCollision(rect))
				{
					return true;
				}
			}
			continue;
		}
		return false;
	}

	const GameObject& GameLevel::ReturnFirstCollisionObjectInList(SDL_Rect& boxColliderToCheck,
		GameObjectList& gameObjectList)
	{
		for (auto levelGameObjectList : gameObjectList._gameObjectList)
		{
			auto component = levelGameObjectList->GetComponent<SG::BoxColliderComponent>();
			if (component)
			{
				if (component->IsCollision(boxColliderToCheck))
				{
					return *levelGameObjectList;
				}
			}
			continue;
		}

		return GameObject();
	}
}
