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
		Vector3(float xy);
		Vector3(float x, float y, float z = 0);

		float X;
		float Y;
		float Z;
	};
}
