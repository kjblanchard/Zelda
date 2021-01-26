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
	struct SGGENGINE_API Vector3
	{
		Vector3();
		Vector3(int xy);
		Vector3(int x, int y, int z = 0);

		int X;
		int Y;
		int Z;
	};
}
