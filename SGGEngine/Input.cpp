#include "pch.h"


#include  "Input.h"



#include <cstdio>
#include <SDL_keyboard.h>
#include <SDL_scancode.h>

namespace SG
{

	Uint8 Input::_currentKeyboardState[SDL_NUM_SCANCODES];
	Uint8 Input::_previousKeyboardState[SDL_NUM_SCANCODES];

	void Input::Startup()
	{
		memset(_previousKeyboardState, 0, sizeof(Uint8) * SDL_NUM_SCANCODES);
		memcpy(_currentKeyboardState, SDL_GetKeyboardState(nullptr), sizeof(Uint8) * SDL_NUM_SCANCODES);
	}

	void Input::UpdateKeyboards()
	{
		memcpy(_previousKeyboardState, _currentKeyboardState, sizeof(Uint8) * SDL_NUM_SCANCODES);
		memcpy(_currentKeyboardState, SDL_GetKeyboardState(NULL), sizeof(Uint8) * SDL_NUM_SCANCODES);
	}

	bool Input::IsKeyDown(const SDL_Scancode key)
	{
		return _currentKeyboardState[key];
	}

	bool Input::IsKeyHeldDown(SDL_Scancode key)
	{
		return _previousKeyboardState[key] && _currentKeyboardState[key];
	}

	bool Input::KeyJustPressed(const SDL_Scancode key)
	{
		return _currentKeyboardState[key] && !_previousKeyboardState[key];
	}

	bool Input::KeyJustReleased(const SDL_Scancode key)
	{
		return !_currentKeyboardState[key] && _previousKeyboardState[key];
	}
}
