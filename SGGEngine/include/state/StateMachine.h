﻿#pragma once
#ifdef SGGENGINE_EXPORTS
#define SGGENGINE_API __declspec(dllexport)
#else
#define SGGENGINE_API __declspec(dllimport)
#endif
#include <map>
#include <memory>
#include "State.h"


namespace SG
{

	template<typename T>
	class StateMachine
	{
	public:

		virtual ~StateMachine() = default;

		void AddStateToGameStateList(T enumKey, State* state);
		void ChangeState(T stateToChangeTo);
		void Update(const double& deltaTime) const;
		void Draw(SpriteBatch& spritebatch);
		State* CurrentState();
		const State& PreviousState() const;


	private:
		std::map<T, std::unique_ptr<SG::State>> _gameStates;
		State* _currentState = nullptr;
		State* _previousState = nullptr;

	};

	template <typename T>
	void StateMachine<T>::AddStateToGameStateList(T enumKey, State* state)
	{
		auto nub
		_gameStates.insert({ enumKey,std::move(state )});
	}


	template <typename T>
	void StateMachine<T>::ChangeState(T stateToChangeTo)
	{
		if (_currentState)
		{
			_currentState->End();
			_previousState = _currentState;
		}
		_currentState = _gameStates.at(stateToChangeTo).get();
		if (_currentState)
			_currentState->Startup();
	}

	template <typename T>
	void StateMachine<T>::Update(const double& deltaTime) const
	{
		if(_currentState)
			_currentState->Update(deltaTime);
	}

	template <typename T>
	void StateMachine<T>::Draw(SpriteBatch& spritebatch)
	{
		_currentState->Draw(spritebatch);
	}

	template <typename T>
	State* StateMachine<T>::CurrentState()
	{
		return _currentState;
	}

	template <typename T>
	const State& StateMachine<T>::PreviousState() const
	{
		return *_previousState;
	}
}