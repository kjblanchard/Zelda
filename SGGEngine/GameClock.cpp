#include "pch.h"


#include  "GameClock.h"

#include <SDL_timer.h>

namespace SG
{

	GameClock::GameClock(const double& msPerTick): _msPerTick(msPerTick), _previousTime(), _currentTime(), _deltaTime(),
	                                               _lagTime()
	{
		_countedFrames = 0;
	}

	GameClock::~GameClock()
	{
	}

	void GameClock::Tick()
	{
		_clock.Tick();
		_currentTime = _clock.GetElapsedTime().Milliseconds();
		_deltaTime = _currentTime - _previousTime;
		_previousTime = _currentTime;
		_lagTime += _deltaTime;
	}

	bool GameClock::ShouldUpdate() const
	{
		return _lagTime > _msPerTick;
	}
}
