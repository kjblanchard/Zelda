#include "pch.h"

#include "collision/Collision.h"
#include <algorithm>

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

		if (!DoShapesIntersect(rectA, rectB))
		{
			auto newRect = SDL_Rect{ 0,0,0,0 };
			return newRect;
		}

			int xmin = (std::max)(rectA.x, rectB.x);
			int xmax = (std::min)(rectA.x+rectA.w, rectB.x + rectB.w);
			int ymin = (std::max)(rectA.y, rectB.y);
			int ymax = (std::min)(rectA.y+rectA.h, rectB.y+rectB.h);
			auto newRect = SDL_Rect{ xmin,ymin,xmax - xmin,ymax - ymin };
			return newRect;
		}

	}
