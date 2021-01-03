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
#include <SDL_gamecontroller.h>
#include <SDL_scancode.h>
#include <SDL_stdinc.h>
#include <vector>

namespace SG
{
	struct GamePad;

	class SGGENGINE_API Input
	{

	public:
		void Startup();
		void UpdateKeyboards();
		static void UpdateJoysticks();

		static bool IsKeyDown(SDL_Scancode key);
		static bool IsKeyDown(SDL_Scancode keys[]);
		static bool IsKeyHeldDown(SDL_Scancode key);
		static bool IsKeyHeldDown(SDL_Scancode keys[]);
		static bool KeyJustPressed(SDL_Scancode key);
		static bool KeyJustPressed(SDL_Scancode keys[]);
		static bool KeyJustPressed(int controllerNum, SDL_GameControllerButton button);
		static bool KeyJustReleased(SDL_Scancode key);
		static bool KeyJustReleased(SDL_Scancode keys[]);

		std::vector<SDL_GameController*> connectedControllers;
		static std::vector<GamePad> controllerInputs;
		static std::vector<GamePad> lastControllerInputs;
		static int numGamepads;

	private:
		static Uint8 _previousKeyboardState[SDL_NUM_SCANCODES];
		static Uint8 _currentKeyboardState[SDL_NUM_SCANCODES];

		const int _joystickDeadZone = 8000;
	};

	struct  GamePad {
		bool buttons[SDL_CONTROLLER_BUTTON_MAX];
		int axis[SDL_CONTROLLER_AXIS_MAX];
	};
}
