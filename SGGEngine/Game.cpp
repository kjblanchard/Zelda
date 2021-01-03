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
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) < 0)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLError);
			return false;
		}
		return true;

	}

	bool Game::HandleEvents()
	{
		Input::UpdateJoysticks();
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0)
		{
			switch (event.type) {
			case SDL_QUIT:
				shouldQuit = true;
				return false;

				// This happens when a device is added
				// A future improvement is to cope with new controllers being plugged in
				// when the game is running
			case SDL_CONTROLLERDEVICEADDED:
				std::cout << "DEVICEADDED cdevice.which = " << event.cdevice.which << std::endl;
				break;

				// If a controller button is pressed
			case SDL_CONTROLLERBUTTONDOWN:
				// Cycle through the controllers
				for (int i = 0; i < _input->numGamepads; i++) {
					// Looking for the button that was pressed
					if (event.cbutton.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(_input->connectedControllers[i]))) {
						// So the relevant state can be updated
						_input->controllerInputs[i].buttons[event.cbutton.button] = true;
					}
				}
				break;

				// Do the same for releasing a button
			case SDL_CONTROLLERBUTTONUP:
				for (int i = 0; i < _input->numGamepads; i++) {
					if (event.cbutton.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(_input->connectedControllers[i]))) {
						_input->controllerInputs[i].buttons[event.cbutton.button] = false;
					}
				}
				break;

				// And something similar for axis motion
			case SDL_CONTROLLERAXISMOTION:
				for (int i = 0; i < _input->numGamepads; i++) {
					if (event.cbutton.which == SDL_JoystickInstanceID(SDL_GameControllerGetJoystick(_input->connectedControllers[i]))) {
						_input->controllerInputs[i].axis[event.caxis.axis] = event.caxis.value;
					}
				}
				break;
			}
		}
		return true;
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
					HandleEvents();
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
		if (Input::KeyJustPressed(0, SDL_CONTROLLER_BUTTON_A))
			printf("JoystickButtonPress");

	}

	void Game::Draw()
	{

	}
}
