#include "pch.h"

#include "collision/Collision.h"

namespace SG
{

	bool Collision::DoShapesIntersect(const SDL_Rect* rectA, const SDL_Rect* rectB)
	{
		auto overlap = SDL_Rect();
		return SDL_IntersectRect(rectA, rectB, &overlap);
	}

	SDL_Rect& Collision::ShapeIntersectionArea(const SDL_Rect* rectA, const SDL_Rect* rectB)
	{
		auto overlap = SDL_Rect();
		SDL_IntersectRect(rectA, rectB, &overlap);
		return overlap;

	}

	Directions Collision::CalculateIntersectionDirection(const SDL_Rect& intersectionAreaRect, const SDL_Rect& yourCollisionBox)
	{
		if (intersectionAreaRect.w < intersectionAreaRect.h)
		{
			if (intersectionAreaRect.x > yourCollisionBox.x)
				return Directions::Right;
			return Directions::Left;
		}
		if (intersectionAreaRect.y > yourCollisionBox.y)
			return Directions::Down;
		return Directions::Up;
	}
}
