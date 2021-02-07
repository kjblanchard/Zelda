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

#include "GameObjectList.h"

namespace SG
{
	class BoxColliderComponent;

	class SGGENGINE_API ILevel
	{
	public:
		bool IsThereACollision(SDL_Rect& boxColliderToCheck, GameObjectTypes listToSearch = GameObjectTypes::Default);

		const GameObject& ReturnFurstCollisionGameObject(SDL_Rect& gameObjectChecking, GameObjectTypes listToSearch = GameObjectTypes::Default);


		GameObjectList TotalGameObjectList;
		GameObjectList TileLayerList;
		GameObjectList SolidLayerList;
		GameObjectList EnemiesLayerList;
		GameObjectList PlayerLayerList;

	private:
		 bool CheckForCollisions(SDL_Rect& rect, GameObjectList& gameObjectList);

		 const GameObject& ReturnFirstCollisionObject(SDL_Rect& boxColliderToCheck, GameObjectList& gameObjectList);
	};



}
