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

#include "state/StateMachine.h"
#include "interfaces/IUpdate.h"
#include <SDL_rect.h>

#include "GameObjectList.h"

namespace SG
{
	template <typename T>
	class  Level :IUpdate
	{
	public:

		Level()
		{
			if (_instance == nullptr)
			{
				_instance = this;
			}
		}

		static Level* GetLevel()
		{
			return _instance;
		}

		void Startup() override;
		void Update(const double& deltaTime) override;
		void Draw(SpriteBatch& spriteBatch) override;
		bool CheckForCollisionInLevel(SDL_Rect& boxColliderToCheck, GameObjectTypes listToSearch = GameObjectTypes::Default);
		void ChangeLevel(T levelToChangeTo);
		void AddLevelToLevelsList(T levelTypeToAdd, State* theActualState);



	private:
		inline static Level* _instance = nullptr;
		StateMachine<T> _levelStateMachine;

	};


	template <typename T>
	void Level<T>::Startup()
	{
		//startup statemachine and generate states.
	}

	template <typename T>
	void Level<T>::Update(const double& deltaTime)
	{
		_levelStateMachine.Update(deltaTime);
	}

	template <typename T>
	void Level<T>::Draw(SpriteBatch& spriteBatch)
	{
		_levelStateMachine.Draw(spriteBatch);
	}

	template <typename T>
	bool Level<T>::CheckForCollisionInLevel(SDL_Rect& boxColliderToCheck, GameObjectTypes listToSearch)
	{
		return false;
	}

	template <typename T>
	void Level<T>::ChangeLevel(T levelToChangeTo)
	{
		_levelStateMachine.ChangeState(levelToChangeTo);
	}

	template <typename T>
	void Level<T>::AddLevelToLevelsList(T levelTypeToAdd, State* theActualState)
	{
		_levelStateMachine.AddStateToGameStateList(levelTypeToAdd, theActualState);
	}
}
