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


#include "GameObject.h"
#include "State.h"

namespace SG
{
	class GameObject;
	class GameObjectList;

	class SGGENGINE_API GameLevel : State
	{
	public:


		bool IsThereACollision(SDL_Rect& boxColliderToCheck, GameObjectTypes listToSearch = GameObjectTypes::Default);

		const GameObject& ReturnFirstCollisionGameObject(SDL_Rect& gameObjectChecking, GameObjectTypes listToSearch = GameObjectTypes::Default);

		protected:

		GameObjectList* TotalGameObjectList = new GameObjectList;
		GameObjectList* TileLayerList = new GameObjectList;
		GameObjectList* SolidLayerList = new GameObjectList;
		GameObjectList* EnemiesLayerList = new GameObjectList;
		GameObjectList* PlayerLayerList = new GameObjectList;

		bool CheckForCollisions(SDL_Rect& rect, GameObjectList& gameObjectList);

		const GameObject& ReturnFirstCollisionObjectInList(SDL_Rect& boxColliderToCheck, GameObjectList& gameObjectList);
	private:
	};
}
