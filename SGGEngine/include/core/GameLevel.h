////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#ifdef SGGENGINE_EXPORTS
#define SGGENGINE_API __declspec(dllexport)
#else
#define SGGENGINE_API __declspec(dllimport)
#endif
#include <SDL_rect.h>
#include <memory>
#include "GameObject.h"
#include "state/State.h"

namespace SG
{
	class GameObject;
	class GameObjectList;

	class SGGENGINE_API GameLevel : public State
	{
	public:
		GameLevel();
		~GameLevel();

		bool IsThereACollision(SDL_Rect& boxColliderToCheck, GameObjectTypes listToSearch = GameObjectTypes::Default);

		GameObject* ReturnFirstCollisionGameObject(SDL_Rect& gameObjectChecking, GameObjectTypes listToSearch = GameObjectTypes::Default);
		std::vector<GameObject*> ReturnAllCollisions(SDL_Rect& rect, GameObjectTypes listToSearch = GameObjectTypes::Default);

		protected:

		std::unique_ptr<GameObjectList> TotalGameObjectList;
		std::unique_ptr<GameObjectList>  TileLayerList;
		std::unique_ptr<GameObjectList>  SolidLayerList;
		std::unique_ptr<GameObjectList>  EnemiesLayerList;
		std::unique_ptr<GameObjectList>  PlayerLayerList;

		bool CheckForCollisions(SDL_Rect& rect, GameObjectList& gameObjectList);
		std::vector<GameObject*> ReturnAllCollissionsInList(SDL_Rect& rect, GameObjectList& gameObjectList);

		GameObject* ReturnFirstCollisionObjectInList(SDL_Rect& boxColliderToCheck, GameObjectList& gameObjectList);
	private:
	};
}
