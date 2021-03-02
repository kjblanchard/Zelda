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

namespace SG
{

	template <class T>
	//class SGGENGINE_API IObjectStateMachine
		class IObjectStateMachine

	{
	public:
		virtual ~IObjectStateMachine() = default;

	protected:
		virtual void GenerateStates() = 0;
		void ChangeState(T stateToChangeTo) const { _objectStateMachine->ChangeState(stateToChangeTo); }
		SG::StateMachine<T>* _objectStateMachine = new SG::StateMachine<T>;
	};
}
