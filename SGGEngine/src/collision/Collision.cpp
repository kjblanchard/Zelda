#include "pch.h"


#include "collision/Collision.h"

namespace SG
{
	bool Collision::DoShapesIntersect(const SDL_Rect& rectA, const SDL_Rect& rectB)
	{
		if (rectA.x < rectB.x + rectB.w &&
			rectA.x + rectA.w > rectB.x &&
			rectA.y < rectB.y + rectB.h &&
			rectA.y + rectA.h > rectB.y)
		{
			return true;
		}
		return false;
	}

	SDL_Rect& Collision::ShapeIntersectionArea(const SDL_Rect& rectA, const SDL_Rect& rectB)
	{
		auto newBoi = SDL_Rect();
		return newBoi;
	}
}
