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
#include <memory>

#include "GameObject.h"

namespace SG
{
	class SGGENGINE_API GameObjectList : public SG::GameObject
	{

	public:
		static std::vector<std::unique_ptr<GameObject>> _gameObjectList;
		static std::vector<std::unique_ptr<GameObject>> _gameObjectStartupList;


		/**
 * \brief This will take in a smart pointer to any game object and run the Startup function on it, and then place it into the actual gameobject list
 * \param gameObject The object that is to be spawned, that is likely created somewhere else in the game that needs to be started and added to the game
 */
		static void AddToGameObjectList(std::unique_ptr<GameObject> gameObject);

		//TODO This is for testing and should be removed and figured out a better way

		static void GameObjectStartup();
	};
}
