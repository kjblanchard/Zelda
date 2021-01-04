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
	class SGGENGINE_API PlayerController : public Controller
	{
	public:
		PlayerController()
		{
		}
		bool IsButtonPressed(ControllerButtons controllerButton) override;
		bool IsButtonHeld(ControllerButtons controllerButton) override;
		bool IsButtonReleased(ControllerButtons controllerButton) override;

		void UpdateControllerMapping(KeyMapping<SDL_Scancode> newKeyboardMap)
		{
			_keyboardMapping = newKeyboardMap;
		}
		void UpdateControllerMapping(KeyMapping<SDL_GameControllerButton> newJoystickMap)
		{
			_joystickMapping = newJoystickMap;
		}

		void UpdateControlType(bool isUsingGamepad)
		{
			_isUsingGamePad = isUsingGamepad;
		}

		void UpdatePlayerNum(uint8_t playerNum)
		{
			_playerNum = playerNum;
		}

	private:
		//TODO fix these to work right and be references / pointers.
		KeyMapping<SDL_Scancode> _keyboardMapping{*DefaultKeyboardMap};
		KeyMapping<SDL_GameControllerButton> _joystickMapping{*DefaultJoystickMap};
		bool _isUsingGamePad{false};
		uint8_t _playerNum{ 0 };
	};
}
