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
	class SGGENGINE_API GameObjectList : public SG::IUpdate
	{

	public:

		void Startup() override;
		void Update(const double& deltaTime) override;
		void Draw(SpriteBatch& spriteBatch) override;
		void Reset();


		/**
		* \brief This will take in a smart pointer to any game object and run the Startup function on it, and then place it into the actual gameobject list
		* \param gameObject The object that is to be spawned, that is likely created somewhere else in the game that needs to be started and added to the game
		*/
		void AddToGameObjectList(GameObject* gameObject);

		const std::vector<GameObject*>& GetGameObjectList() const { return _gameObjectList; }
	private:
		std::vector<GameObject*> _gameObjectList;
		void GameObjectStartup();
		std::vector<GameObject*> _gameObjectStartupList;
	};
}
