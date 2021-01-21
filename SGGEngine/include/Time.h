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
#include <cstdint>

namespace SG
{
	struct SGGENGINE_API Time
	{
		Time() : _timeValue(0){}
		Time(uint32_t msValue) :_timeValue(msValue) {}
		double Seconds() const
		{
			return _timeValue / 1000.00;
		}
		uint32_t Milliseconds() const
		{
			return _timeValue;
		}

	private:
		uint32_t _timeValue;

	};
}
