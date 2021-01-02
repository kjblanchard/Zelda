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

#include "Controller.h"

namespace SG
{
	class SGGENGINE_API PlayerController : Controller
	{
	public:
		PlayerController()
		{
			_controllerMapping = std::make_unique<ControllerMapping>();
		}
		bool IsButtonPressed(ControllerButtons controllerButton) override;
		bool IsButtonHeld(ControllerButtons controllerButton) override;
		bool IsButtonReleased(ControllerButtons controllerButton) override;

		void UpdateControllerMapping(ControllerMapping* _newMapping)
		{
			_controllerMapping.reset(_newMapping);
		}

	private:
		std::unique_ptr<ControllerMapping> _controllerMapping;
	};
}
