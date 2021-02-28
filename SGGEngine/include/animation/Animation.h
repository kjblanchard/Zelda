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
#include "graphics/Graphics.h"
#include "graphics/Spritesheet.h"
#include "data/Point.h"
#include "core/World.h"

namespace SG
{
	/// <summary>
	/// The base class used for every animation
	/// </summary>
	/// <typeparam name="T">The enum type of the animation, this is used by the animation controller</typeparam>
	template <typename T>
	class Animation
	{
	public:
		/// <summary>
		/// The animation that will be played by a animation controller, gets the graphics if it hasn't already
		/// </summary>
		Animation() {
			if (!_graphics) _graphics = SG::World::GetGraphics();
		}
		virtual ~Animation();
		T AnimationEnumType {};
		std::vector < std::pair<Point, int>> LocationAndLengthOfAnimation;
		Spritesheet* SpriteSheet = nullptr;

		int TotalAnimationFrames() const { return LocationAndLengthOfAnimation.size(); }
		/// <summary>
		/// Returns the location that this animation should be drawn
		/// </summary>
		/// <param name="currentFrame">The current frame that this animation is on</param>
		/// <returns>A point from the vector of locations/lengths of the animation</returns>
		Point DrawLocation(int currentFrame)
		{

			return LocationAndLengthOfAnimation[currentFrame].first * 32;
		}
	protected:
	 inline static Graphics* _graphics = nullptr;
	};


	template <typename T>
	Animation<T>::~Animation()
	{
	}


}
