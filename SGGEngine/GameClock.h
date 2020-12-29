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
#include "Clock.h"

namespace SG
{

	class SGGENGINE_API GameClock
	{
	public:
		GameClock(const double& msPerTick = 1000.00/60);
		~GameClock();
		void Tick();
		bool ShouldUpdate() const;
		double DeltaTime() const { return _lagTime; }
		void Update() { _lagTime -= _msPerTick; }
		double TotalTime() const { return  _clock.CurrentTime - _clock.StartTime; }
		int _countedFrames;
	private:
		double _msPerTick;


		double _previousTime;
		double _currentTime;
		double _deltaTime;
		double _lagTime;
		Clock _clock;
	};
}
