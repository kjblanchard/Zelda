#include "pch.h"
#include "Game.h"
#include <iostream>
#include <SDL.h>


namespace SG
{


	Game::Game(const Point screenSize)
		: _screenSize(screenSize), _gameWindow(nullptr), _windowSurface(nullptr), _previousClockInMs{0.0},
		  _currentClockInMs(0),
		  _elapsedTimeInMs(0), _lagTimeInMs(0), _fps(0)
	{
	}

	Game::~Game()
	{
		SDL_DestroyWindow(_gameWindow);
		SDL_Quit();
		printf("Bye");
	}

	void Game::Loop()
	{
		if(!Startup())
			return;

	}




	bool Game::Startup()
	{

		//Initialize SDL
		if(!InitializeSdl())
			return false;
		if (!CreateGameWindow())
			return false;
		//Get window surface
		_windowSurface = SDL_GetWindowSurface(_gameWindow);

		 //Fill the surface white
		SDL_FillRect(_windowSurface, nullptr, SDL_MapRGB(_windowSurface->format, 0xff, 0xFF, 0xFF));

		 //Update the surface
		SDL_UpdateWindowSurface(_gameWindow);

		 //Wait two seconds
		SDL_Delay(3000);

		return true;
	}
	bool Game::InitializeSdl()
	{
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			return false;
		}
		printf("We gucci");
		return true;

	}

	bool Game::CreateGameWindow()
	{
		_gameWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenSize.X, _screenSize.Y, SDL_WINDOW_SHOWN);
		if (_gameWindow)
			return true;
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
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
