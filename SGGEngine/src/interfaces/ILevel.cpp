#include "pch.h"


#include "interfaces/ILevel.h"

#include "components/BoxColliderComponent.h"

namespace SG
{
	bool ILevel::IsThereACollision(SDL_Rect& gameObjectChecking, GameObjectTypes listToSearch)
	{
		switch (listToSearch)
		{
		case GameObjectTypes::Default:
			return CheckForCollisions(gameObjectChecking, TotalGameObjectList);
		case GameObjectTypes::SolidTile:
			return CheckForCollisions(gameObjectChecking, SolidLayerList);
		case GameObjectTypes::Enemy:
			return CheckForCollisions(gameObjectChecking, EnemiesLayerList);
		case GameObjectTypes::Player:
			return CheckForCollisions(gameObjectChecking, PlayerLayerList);
		default:
			return false;

		}
	}

	const GameObject& ILevel::ReturnFurstCollisionGameObject(SDL_Rect& gameObjectChecking, GameObjectTypes listToSearch)
	{
		switch (listToSearch)
		{
		case GameObjectTypes::Default:
			return ReturnFirstCollisionObject(gameObjectChecking, TotalGameObjectList);
		case GameObjectTypes::SolidTile:
			return ReturnFirstCollisionObject(gameObjectChecking, SolidLayerList);
		case GameObjectTypes::Enemy:
			return ReturnFirstCollisionObject(gameObjectChecking, EnemiesLayerList);
		case GameObjectTypes::Player:
			return ReturnFirstCollisionObject(gameObjectChecking, PlayerLayerList);
		default:
			return GameObject();

		}
	}

	bool ILevel::CheckForCollisions(SDL_Rect& rect, GameObjectList& gameObjectList)
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

	const GameObject& ILevel::ReturnFirstCollisionObject(SDL_Rect& boxColliderToCheck, GameObjectList& gameObjectList)
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
