#include "pch.h"
#include "Game.h"
#include <iostream>
#include <SDL.h>
#include "DebugHandler.h"
#include "GameClock.h"
#include "Graphics.h"



namespace SG
{
	std::unique_ptr<Graphics>  Game::_graphics = nullptr;
	Game* Game::_instance = nullptr;


	Game::Game(const Point& screenSize)
		: _screenSize(screenSize), _gameWindow(nullptr)
	{
		_graphics = std::make_unique<class Graphics>(_screenSize);
		_gameClock = std::make_unique<GameClock>();
		if (_instance == nullptr)
			_instance = this;
	}


	Game::~Game()
	{
		SDL_DestroyWindow(_gameWindow);
		SDL_Quit();
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

	void Game::HandleShouldQuit()
	{
		while (SDL_PollEvent(&_events) != 0)
		{
			if (_events.type == SDL_QUIT)
			{
				shouldQuit = true;
			}
		}
	}

	void Game::Loop()
	{
		memset(_previousState, 0, sizeof(Uint8) * SDL_NUM_SCANCODES);
		memcpy(_currentState, SDL_GetKeyboardState(NULL), sizeof(Uint8) * SDL_NUM_SCANCODES);

		while (!shouldQuit)
		{
			_gameClock->Tick();
			if (_gameClock->ShouldUpdate())
			{
				if (_gameClock->GameIsLagging())
					DebugHandler::PrintErrorMessage(ErrorCodes::GameSlowdown, _gameClock->DeltaTime());
				while (_gameClock->ShouldUpdate())
				{
					HandleShouldQuit();
					HandleInput();
					Update(_gameClock->MsPerFrame());
					_gameClock->UpdateClockTimer();
				}
				Draw();
			}
		}
	}

	void Game::HandleInput()
	{
			memcpy(_previousState, _currentState, sizeof(Uint8) * SDL_NUM_SCANCODES);
			memcpy(_currentState, SDL_GetKeyboardState(NULL), sizeof(Uint8) * SDL_NUM_SCANCODES);
		if (_currentState[SDL_SCANCODE_RETURN]) {
			printf("<RETURN> is pressed.\n");
		}
		else if (_previousState[SDL_SCANCODE_RETURN])
		{
			printf("Return was pressed. \n");
		}
	}


	void Game::Update(const double& deltaTime)
	{

	}

	void Game::Draw()
	{

	}
}
