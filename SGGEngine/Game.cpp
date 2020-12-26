#include "pch.h"
#include "Game.h"
#include <iostream>


namespace SG
{
	Game::Game()
		: _previousClockInMs{ 0.0 }, _currentClockInMs(0), _elapsedTimeInMs(0), _lagTimeInMs(0), _fps(0)
	{
		printf("Hello");
	}

	Game::~Game()
	{
		printf("Bye");
	}

	void Game::Loop()
	{
		//while (true)
		//{
		//	CalculateFrameTime();
		//	HandleInput();
		//	Tick();
		//}
	}

	void Game::CalculateFrameTime()
	{
		//_currentClockInMs = _gameClock.getElapsedTime().asMilliseconds();
		_elapsedTimeInMs = _currentClockInMs - _previousClockInMs;
		_previousClockInMs = _currentClockInMs;
		_lagTimeInMs += _elapsedTimeInMs;
	}

	void Game::HandleInput()
	{
	}

	void Game::Tick()
	{
		while (_lagTimeInMs >= _updateTime)
		{
			_fps = CalculateFps();
			std::cout << _lagTimeInMs;
			Update(_lagTimeInMs);
			_lagTimeInMs -= _updateTime;
		}
		Draw();
	}

	float Game::CalculateFps()
	{
		return 0.0;
	}

	void Game::Update(const double& deltaTime)
	{
		printf("Updating");
	}

	void Game::Draw()
	{
	}
}
