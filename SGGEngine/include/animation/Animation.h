﻿////////////////////////////////////////////////////////////
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
#include "data/Point.h"

namespace SG
{

	template <typename T>
	class Animation
	{
	public:
		virtual ~Animation();
		T AnimationEnumType {};
		std::vector < std::pair<Point, int>> LocationAndLengthOfAnimation;
		Spritesheet* SpriteSheet = nullptr;

		int TotalAnimationFrames() const { return LocationAndLengthOfAnimation.size(); }
		const Point DrawLocation(int currentFrame)
		{

			return LocationAndLengthOfAnimation[currentFrame].first * 32;
		}

	};

	template <typename T>
	Animation<T>::~Animation()
	{
	}


}
