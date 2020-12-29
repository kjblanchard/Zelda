#include "pch.h"
#include "Game.h"

#include <iostream>
#include <SDL.h>
#include "DebugHandler.h"
#include "GameClock.h"


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
		printf("Bye");
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

	void Game::Loop()
	{
		_gameClock->Tick();
		while(_gameClock->ShouldUpdate())
		{
			Update(_gameClock->DeltaTime());
			_gameClock->Update();
			_gameClock->_countedFrames++;
		}
		Draw();
	}

	void Game::HandleInput()
	{
	}


	void Game::Update(const double& deltaTime)
	{
		if(_gameClock->_countedFrames>600)
		{

		}
		int fps = (_gameClock->TotalTime() / 1000) / _gameClock->_countedFrames;
		std::cout << std::to_string(fps) << std::endl;
	}

	void Game::Draw()
	{
	}
}
