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
#include "interfaces/IUpdate.h"
#include "state/StateMachine.h"

namespace SG
{
	class GameLevel;

	template <typename T>
	class Level : public IUpdate
	{
	public:

		Level()
		{
			if(_instance == nullptr)
			{
				_instance = this;
			}
		}
		inline static Level* _instance;
		StateMachine<T> LevelStateMachine;


		void Startup() override;
		void Update(const double& deltaTime) override;
		void Draw(SpriteBatch& spriteBatch) override;
		static  Level* GetLevel()
		{
			return _instance;
		}

		GameLevel* GetCurrentGameLevel()
		{
			return dynamic_cast<SG::GameLevel*>(LevelStateMachine.CurrentState());
		}

		void ChangeLevel(T gameLevelToChangeTo);
		virtual void AddAllGameLevels() = 0;
	};

	template <typename T>
	void Level<T>::Startup()
	{
		AddAllGameLevels();
	}

	template <typename T>
	void Level<T>::Update(const double& deltaTime)
	{
		if(LevelStateMachine.CurrentState())
		{
			LevelStateMachine.CurrentState()->Update(deltaTime);
		}
	}

	template <typename T>
	void Level<T>::Draw(SpriteBatch& spriteBatch)
	{
		if(LevelStateMachine.CurrentState())
		{
			LevelStateMachine.Draw(spriteBatch);
		}
	}

	template <typename T>
	void Level<T>::ChangeLevel(T gameLevelToChangeTo)
	{
		LevelStateMachine.ChangeState(gameLevelToChangeTo);
	}
}
