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
#include <cinttypes>
#include "Time.h"

namespace SG
{
	/// <summary>
	/// Holds Time Variables, it is automatically initialized with the start time when a new timer is created.
	/// </summary>
	struct SGGENGINE_API Clock
	{
		Clock();
		Time GetElapsedTime() const;
		void Tick();

		uint32_t StartTime;
		uint32_t CurrentTime;
	};


}
