#include "pch.h"
#include "Game.h"
#include <iostream>
#include <SDL.h>
#include "DebugHandler.h"
#include "GameClock.h"
#include "Graphics.h"
#include "Input.h"


namespace SG
{
	//statics
	std::unique_ptr<Graphics>  Game::_graphics = nullptr;
	Game* Game::_instance = nullptr;


	Game::Game(const Point& screenSize)
		: _screenSize(screenSize), _gameWindow(nullptr), _gameClock{std::make_unique<GameClock>()},_input{std::make_unique<Input>()}
	{
		_graphics = std::make_unique<class Graphics>(_screenSize);
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
		_input->Startup();
		return true;
	}

	bool Game::InitializeSdl()
	{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) < 0)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLError);
			return false;
		}
		return true;

	}


	void Game::Loop()
	{
		while (!shouldQuit)
		{
			_gameClock->Tick();
			if (_gameClock->ShouldUpdate())
			{
				if (_gameClock->GameIsLagging())
					DebugHandler::PrintErrorMessage(ErrorCodes::GameSlowdown, _gameClock->DeltaTime());
				while (_gameClock->ShouldUpdate())
				{
					HandleInput();
					Update(_gameClock->MsPerFrame());
					_gameClock->UpdateClockTimer();
				}
				Draw();
			}
		}
	}

	bool Game::HandleEvents()
	{
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				shouldQuit = true;
				return false;
			}
			_input->HandleJoystickEvent(event);
		}
		return true;
	}

	void Game::HandleInput()
	{
		Input::UpdatePreviousJoystickState();
		HandleEvents();
		Input::UpdateKeyboardStates();
	}


	void Game::Update(const double& deltaTime)
	{

	}

	void Game::Draw()
	{

	}
}
