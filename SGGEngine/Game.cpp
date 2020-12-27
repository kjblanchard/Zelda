#include "pch.h"
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>



namespace SG
{

	Game::Game(const Point& screenSize)
		: _screenSize(screenSize), _gameWindow(nullptr),
		  _previousClockInMs{0.0},
		  _currentClockInMs(0), _elapsedTimeInMs(0), _lagTimeInMs(0), _fps(0)
	{
		_graphics = std::make_unique<class Graphics>(_screenSize);
		if (_instance == nullptr)
			_instance = this;
	}
	std::unique_ptr<Graphics>  Game::_graphics = nullptr;

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
		//_graphics->Draw();
	}

	Game* Game::GetGame()
	{
		return _instance;
	}

	Graphics* Game::GetGraphics()
	{
		return _graphics.get();
	}


	Game* Game::_instance = nullptr;


	bool Game::Startup()
	{
		if(!InitializeSdl())
			return false;
		if (!_graphics->Startup())
			return false;
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
