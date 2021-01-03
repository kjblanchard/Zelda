#include "pch.h"


#include  "Input.h"



#include <cstdio>
#include <iostream>
#include <ostream>
#include <SDL.h>
#include <SDL_keyboard.h>
#include <SDL_scancode.h>

namespace SG
{
	//TODO fix these maybe?  Also refactor this and the game class and controller classes badly...
	int Input::numGamepads;
	std::vector<GamePad> Input::controllerInputs;
	std::vector<GamePad> Input::lastControllerInputs;

	Uint8 Input::_currentKeyboardState[SDL_NUM_SCANCODES];
	Uint8 Input::_previousKeyboardState[SDL_NUM_SCANCODES];

	void Input::Startup()
	{
		memset(_previousKeyboardState, 0, sizeof(Uint8) * SDL_NUM_SCANCODES);
		memcpy(_currentKeyboardState, SDL_GetKeyboardState(nullptr), sizeof(Uint8) * SDL_NUM_SCANCODES);



		int nJoysticks = SDL_NumJoysticks();
		numGamepads = 0;
		//Count GamePads
		for (int i = 0; i < nJoysticks; i++)
			if (SDL_IsGameController(i))
				numGamepads++;

		// If we have some controllers attached
		if (numGamepads > 0)
		{
			for (int i = 0; i < numGamepads; i++)
			{
				// Open the controller and add it to our list
				SDL_GameController* pad = SDL_GameControllerOpen(i);
				if (SDL_GameControllerGetAttached(pad) == 1)
					connectedControllers.push_back(pad);
				else
					std::cout << "SDL_GetError() = " << SDL_GetError() << std::endl;
			}
			SDL_GameControllerEventState(SDL_ENABLE);
		}

		// Vectors are empty to begin with, this sets their size
		controllerInputs.resize(numGamepads);
		lastControllerInputs.resize(numGamepads);

		// Set the status of the controllers to "nothing is happening"
		for (int i = 0; i < numGamepads; i++) {
			for (int a = 0; a < SDL_CONTROLLER_AXIS_MAX; a++) {
				controllerInputs[i].axis[a] = 0;
				lastControllerInputs[i].axis[a] = 0;
			}
			for (int b = 0; b < SDL_CONTROLLER_BUTTON_MAX; b++) {
				controllerInputs[i].buttons[b] = false;
				lastControllerInputs[i].buttons[b] = false;
			}
		}
	}

	void Input::UpdateKeyboards()
	{
		memcpy(_previousKeyboardState, _currentKeyboardState, sizeof(Uint8) * SDL_NUM_SCANCODES);
		memcpy(_currentKeyboardState, SDL_GetKeyboardState(NULL), sizeof(Uint8) * SDL_NUM_SCANCODES);


	}

	void Input::UpdateJoysticks()
	{
		//Update Joysticks
		for (int i = 0; i < numGamepads; i++) {
			for (int a = 0; a < SDL_CONTROLLER_AXIS_MAX; a++) {
				lastControllerInputs[i].axis[a] = controllerInputs[i].axis[a];
			}
			for (int b = 0; b < SDL_CONTROLLER_BUTTON_MAX; b++) {
				lastControllerInputs[i].buttons[b] = controllerInputs[i].buttons[b];
			}
		}
	}

	bool Input::IsKeyDown(const SDL_Scancode key)
	{
		return _currentKeyboardState[key];
	}

	bool Input::IsKeyDown(SDL_Scancode keys[])
	{
		for (int i = 0; i < 2; ++i)
		{
			if (IsKeyDown(keys[i]))
				return true;
		}
		return false;
	}

	bool Input::IsKeyHeldDown(SDL_Scancode key)
	{
		return _previousKeyboardState[key] && _currentKeyboardState[key];
	}
	bool Input::IsKeyHeldDown(SDL_Scancode keys[])
	{
		for (int i = 0; i < 2; ++i)
		{
			if (IsKeyHeldDown(keys[i]))
				return true;
		}
		return false;
	}

	bool Input::KeyJustPressed(const SDL_Scancode key)
	{
		return _currentKeyboardState[key] && !_previousKeyboardState[key];
	}
	bool Input::KeyJustPressed(SDL_Scancode keys[])
	{
		for (int i = 0; i < 2; ++i)
		{
			if (KeyJustPressed(keys[i]))
				return true;
		}
		return false;
	}

	bool Input::KeyJustPressed(int controllerNum, SDL_GameControllerButton button)
	{
		if (controllerNum < 0 || controllerNum > numGamepads) return false;

		return controllerInputs[controllerNum].buttons[button] && !lastControllerInputs[controllerNum].buttons[button];
		//return controllerInputs[controllerNum].buttons[button];

	}

	bool Input::KeyJustReleased(const SDL_Scancode key)
	{
		return !_currentKeyboardState[key] && _previousKeyboardState[key];
	}

	bool Input::KeyJustReleased(SDL_Scancode keys[])
	{
		for (int i = 0; i < 2; ++i)
		{
			if (KeyJustReleased(keys[i]))
				return true;
		}
		return false;
	}



}
