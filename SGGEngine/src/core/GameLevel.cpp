#include "pch.h"

#include "core/GameObjectList.h"
#include  "core/GameLevel.h"
#include "tilemap/TileMap.h"
#include "components/BoxColliderComponent.h"

namespace SG
{
	GameLevel::GameLevel() : TotalGameObjectList(std::make_unique<GameObjectList>()), TileLayerList(std::make_unique<GameObjectList>()), SolidLayerList(std::make_unique<GameObjectList>()), EnemiesLayerList(std::make_unique<GameObjectList>()), PlayerLayerList(std::make_unique<GameObjectList>())
	{
	}

	GameLevel::~GameLevel()
	{
		TotalGameObjectList->Reset();
		TileLayerList->Reset();
		SolidLayerList->Reset();
		EnemiesLayerList->Reset();
		PlayerLayerList->Reset();
	}

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
		case GameObjectTypes::Tile:
			return ReturnFirstCollisionObjectInList(gameObjectChecking, *TileLayerList);
		}
		return {};
	}

	std::vector<GameObject*> GameLevel::ReturnAllCollisions(SDL_Rect& rect, GameObjectTypes listToSearch)
	{
		switch (listToSearch)
		{
		case GameObjectTypes::Default:
			return ReturnAllCollissionsInList(rect, *TotalGameObjectList);
		case GameObjectTypes::SolidTile:
			return ReturnAllCollissionsInList(rect, *SolidLayerList);
		case GameObjectTypes::Enemy:
			return ReturnAllCollissionsInList(rect, *EnemiesLayerList);
		case GameObjectTypes::Player:
			return ReturnAllCollissionsInList(rect, *PlayerLayerList);
		case GameObjectTypes::Tile:
			return ReturnAllCollissionsInList(rect, *TileLayerList);
		}
		return {};
	}

	bool GameLevel::CheckForCollisions(SDL_Rect& rect, GameObjectList& gameObjectList)
	{
		for (auto levelGameObjectList : gameObjectList.GetGameObjectList())
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

	std::vector<GameObject*> GameLevel::ReturnAllCollissionsInList(SDL_Rect& rect, GameObjectList& gameObjectList)
	{
		std::vector<GameObject*> collisionsGameObjectList = {};
		for (auto levelGameObjectList : gameObjectList.GetGameObjectList())
		{
			auto component = levelGameObjectList->GetComponent<SG::BoxColliderComponent>();
			if (component)
			{
				if (component->IsCollision(rect))
				{
					collisionsGameObjectList.push_back(levelGameObjectList);
				}
			}
		}
		return collisionsGameObjectList;
	}

	const GameObject& GameLevel::ReturnFirstCollisionObjectInList(SDL_Rect& boxColliderToCheck,
		GameObjectList& gameObjectList)
	{
		for (auto levelGameObjectList : gameObjectList.GetGameObjectList())
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
