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
	std::unique_ptr<Graphics>  Game::_graphics = nullptr;
	Game* Game::_instance = nullptr;


	Game::Game(const Point& screenSize)
		: _screenSize(screenSize), _gameWindow(nullptr)
	{
		_graphics = std::make_unique<class Graphics>(_screenSize);
		_gameClock = std::make_unique<GameClock>();
		_input = new Input();
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
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
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
		_playerController = new PlayerController;


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
		_input->UpdateKeyboards();
	}


	void Game::Update(const double& deltaTime)
	{


		if (_playerController->IsButtonPressed(ControllerButtons::A))
			printf("Key just pressed\n");
		if (_playerController->IsButtonReleased(ControllerButtons::A))
			printf("Key just released\n");
		if (_playerController->IsButtonHeld(ControllerButtons::A))
			printf("Key held\n");


	}

	void Game::Draw()
	{

	}
}
