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
#include <map>

namespace SG
{
	enum class ControllerButtons
	{
		Default = 0,
		Up = 1,
		Right = 2,
		Down = 3,
		Left = 4,
		Y = 5,
		B = 6,
		A = 7,
		X = 8,
		Start = 9,
		Select = 10
	};

	class SGGENGINE_API Controller
	{
	public:
		virtual ~Controller() = default;
		virtual bool IsButtonPressed(ControllerButtons controllerButton) = 0;
		virtual bool IsButtonReleased(ControllerButtons controllerButton) = 0;
		virtual bool IsButtonHeld(ControllerButtons controllerButton) = 0;
	protected:


	};

	class SGGENGINE_API ControllerMapping
	{
	public:

		SDL_Scancode UpButton[2]{ SDL_SCANCODE_UP };
		SDL_Scancode RightButton[2]{ SDL_SCANCODE_RIGHT };
		SDL_Scancode DownButton[2]{ SDL_SCANCODE_DOWN };
		SDL_Scancode LeftButton[2]{ SDL_SCANCODE_LEFT };
		SDL_Scancode YButton[2]{SDL_SCANCODE_1};
		SDL_Scancode BButton[2]{ SDL_SCANCODE_X };
		SDL_Scancode AButton[2]{ SDL_SCANCODE_SPACE };
		SDL_Scancode XButton[2]{ SDL_SCANCODE_2 };
		SDL_Scancode StartButton[2]{ SDL_SCANCODE_RETURN };
		SDL_Scancode SelectButton[2]{ SDL_SCANCODE_TAB };



	};
}
