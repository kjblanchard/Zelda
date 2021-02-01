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

	struct Animation
	{
	public:
		int AnimationEnumType;
		std::vector < std::pair<Point, int>> LocationAndLengthOfAnimation;
		Spritesheet* SpriteSheet = nullptr;
		int CurrentFrameInAnimation = 0;
		double CurrentAnimationTime = 0;
		Point CurrentFrame = SG::Point(0,0);
		static std::vector<int> FrameCallbacks;

	};
}
