#include "pch.h"
#include "Game.h"
#include <SDL.h>
#include "DebugHandler.h"


namespace SG
{
	std::unique_ptr<Graphics>  Game::_graphics = nullptr;
	Game* Game::_instance = nullptr;


	Game::Game(const Point& screenSize)
		: _screenSize(screenSize), _gameWindow(nullptr),
		_previousClockInMs{ 0.0 },
		_currentClockInMs(0), _elapsedTimeInMs(0), _lagTimeInMs(0), _fps(0)
	{
		_graphics = std::make_unique<class Graphics>(_screenSize);
		if (_instance == nullptr)
			_instance = this;
	}


	Game::~Game()
	{
		SDL_DestroyWindow(_gameWindow);
		SDL_Quit();
		printf("Bye");
	}

	void Game::Loop()
	{
	}

	Game* Game::GetGame()
	{
		return _instance;
	}

	Graphics* Game::GetGraphics()
	{
		return _graphics.get();
	}

	bool Game::Startup()
	{
		if (!InitializeSdl())
			return false;
		if (!_graphics->Startup())
			return false;
		return true;
	}
	bool Game::InitializeSdl()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLError);
			return false;
		}
		return true;

	}


	void Game::CalculateFrameTime()
	{
		//_currentClockInMs = _gameClock.getElapsedTime().asMilliseconds();
		//_elapsedTimeInMs = _currentClockInMs - _previousClockInMs;
		//_previousClockInMs = _currentClockInMs;
		//_lagTimeInMs += _elapsedTimeInMs;
	}

	void Game::HandleInput()
	{
	}

	void Game::Tick()
	{
		//while (_lagTimeInMs >= _updateTime)
		//{
		//	_fps = CalculateFps();
		//	std::cout << _lagTimeInMs;
		//	Update(_lagTimeInMs);
		//	_lagTimeInMs -= _updateTime;
		//}
		//Draw();
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
