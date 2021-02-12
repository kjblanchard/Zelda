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
#include <SDL_rect.h>

namespace SG
{
	enum class Directions
	{
		Up,
		Right,
		Down,
		Left
	};

	class SGGENGINE_API Collision
	{
	public:
		//static bool DoShapesIntersect(const SDL_Rect& rectA, const SDL_Rect& rectB);
		static bool DoShapesIntersect(const SDL_Rect* rectA, const SDL_Rect* rectB);

		//static SDL_Rect& ShapeIntersectionArea(const SDL_Rect& rectA, const SDL_Rect& rectB);

		static SDL_Rect& ShapeIntersectionArea(const SDL_Rect* rectA, const SDL_Rect* rectB);

		static Directions CalculateIntersectionDirection(const SDL_Rect& intersectionAreaRect, const SDL_Rect& yourCollisionBox);
 	};
}
