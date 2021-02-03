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

namespace SG
{
	/**
	 * \brief Has a X and a Y integer that can be used for many things.
	 */
	struct SGGENGINE_API Point
	{
		Point()
			:X(0), Y(0)
		{

		}
		Point(int xy): X(0), Y(0)
		{
		}

		Point(int x, int y)
			:X(x), Y(y)
		{

		}
		Point operator * (int mult)
		{
			return Point(X * mult, Y * mult);
		}
		int X;
		int Y;
	};
}
