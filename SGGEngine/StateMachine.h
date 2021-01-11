#pragma once
#include <map>
#include <memory>
#include "State.h"


namespace SG
{

	template<typename T>
	class StateMachine
	{
	public:

		void AddStateToGameStateList(T enumKey, std::unique_ptr<SG::State> state);
		void ChangeState(T stateToChangeTo);

	private:
		std::map<T, std::unique_ptr<SG::State>> _gameStates;
		State* _currentState = nullptr;
		State* _previousState = nullptr;

	};

	template <typename T>
	void StateMachine<T>::AddStateToGameStateList(T enumKey, std::unique_ptr<SG::State> state)
	{
		_gameStates.insert(enumKey, state);
	}

	template <typename T>
	void StateMachine<T>::ChangeState(T stateToChangeTo)
	{
		if(_currentState)
		{
			_currentState->End();
			_previousState = _currentState;
		}
		_currentState = _gameStates.at(stateToChangeTo).get();
		if (_currentState)
			_currentState->Startup();
	}
}
