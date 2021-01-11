#pragma once
#include "StateMachine.h"

namespace SG
{
	class State
	{

	public:
		virtual void Startup() = 0;
		virtual void Update() = 0;
		virtual void End() = 0 ;

	protected:
		
	};

}
