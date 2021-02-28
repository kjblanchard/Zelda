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
			if (!_instance)
				_instance = this;
		}

		static  Level* GetLevel()
		{
			return _instance;
		}

		void Startup() override;
		void Update(const double& deltaTime) override;
		void Draw(SpriteBatch& spriteBatch) override;

		GameLevel* GetCurrentGameLevel()
		{
			return dynamic_cast<SG::GameLevel*>(LevelStateMachine.CurrentState());
		}

		void ChangeLevel(T gameLevelToChangeTo);

	protected:
		inline static Level* _instance;
		virtual void AddAllGameLevels() = 0;
		StateMachine<T> LevelStateMachine;
	};

	template <typename T>
	void Level<T>::Startup()
	{
		AddAllGameLevels();
	}

	template <typename T>
	void Level<T>::Update(const double& deltaTime)
	{
			LevelStateMachine.Update(deltaTime);

	}

	template <typename T>
	void Level<T>::Draw(SpriteBatch& spriteBatch)
	{
			LevelStateMachine.Draw(spriteBatch);
	}

	template <typename T>
	void Level<T>::ChangeLevel(T gameLevelToChangeTo)
	{
		LevelStateMachine.ChangeState(gameLevelToChangeTo);
	}
}
