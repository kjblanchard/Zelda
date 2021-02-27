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

#include "data/Directions.h"

namespace SG
{

	/// <summary>
	/// The main collision class for the game.  Everything is statics, this could be moved if wanted to to be non static
	/// </summary>
	class SGGENGINE_API Collision
	{
	public:
		/// <summary>
		/// Returns a bool for if two rectangles intersect
		/// </summary>
		/// <param name="rectA">First rectangle to compare with</param>
		/// <param name="rectB">Second rectangle to compare to</param>
		/// <returns>True if the rectangles intersect, false if not</returns>
		static bool DoShapesIntersect(const SDL_Rect* rectA, const SDL_Rect* rectB);

		/// <summary>
		/// Gets the intersection area between two rectangles
		/// </summary>
		/// <param name="rectA">The first rectangle to compare with</param>
		/// <param name="rectB">Second rectangle to compare to</param>
		/// <returns>Returns a rectangle with the intersection area</returns>
		static const SDL_Rect& ShapeIntersectionArea(const SDL_Rect* rectA, const SDL_Rect* rectB);

		/// <summary>
		/// Calculates the intersection between a collider box and the intersection area
		/// </summary>
		/// <param name="intersectionAreaRect">Returned from Shapeintersectionarea() most likely</param>
		/// <param name="yourCollisionBox">Your box collider to compare it to</param>
		/// <returns>Returns an enum value of directions as to which direction the intersection is in</returns>
		static Directions CalculateIntersectionDirection(const SDL_Rect& intersectionAreaRect, const SDL_Rect& yourCollisionBox);
 	};
}
