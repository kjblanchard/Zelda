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
#include <SDL_scancode.h>
#include <SDL_stdinc.h>

namespace SG
{
	class SGGENGINE_API Input
	{

	public:
		void Startup();
		void UpdateKeyboards();

		static bool IsKeyDown(SDL_Scancode key);
		static bool IsKeyDown(SDL_Scancode keys[]);
		static bool IsKeyHeldDown(SDL_Scancode key);
		static bool IsKeyHeldDown(SDL_Scancode keys[]);
		static bool KeyJustPressed(SDL_Scancode key);
		static bool KeyJustPressed(SDL_Scancode keys[]);
		static bool KeyJustReleased(SDL_Scancode key);
		static bool KeyJustReleased(SDL_Scancode keys[]);


	private:
		static Uint8 _previousKeyboardState[SDL_NUM_SCANCODES];
		static Uint8 _currentKeyboardState[SDL_NUM_SCANCODES];

		const int _joystickDeadZone = 8000;
	};
}
