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
#include "Component.h"

namespace SG
{
	class Controller;

	class SGGENGINE_API InputComponent : Component
	{
	public:
		InputComponent(Controller* controller, GameObject* gameObject = nullptr);

		void Startup() override
		{

		}
		void TakeControl(Controller* controllerToUse);

		Controller* CurrentController;
	};
}
