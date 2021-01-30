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
#include <vector>



#include "Graphics.h"
#include "Spritesheet.h"
#include "World.h"
#include "data/Point.h"

namespace SG
{

	class SGGENGINE_API Animation
	{
	public:

		int CurrentFrameInAnimation = 0;
		std::vector < std::pair<Point, double>> LocationAndLengthOfAnimation =
		{
			{Point(0,1),160.0},
			{Point(1,1),160.0},

		};

		Spritesheet* SpriteSheet = World::GetGraphics()->LoadFromSpriteSheet(SpriteSheetEnum::LinkWalking);
		double CurrentAnimationTime = 0;

		Point Update(const double& deltaTime);

	};
}
