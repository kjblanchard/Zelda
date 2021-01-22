﻿#include "pch.h"
#include "World.h"
#include <iostream>
#include <SDL.h>
#include "DebugHandler.h"
#include "GameClock.h"
#include "GameObjectList.h"
#include "Graphics.h"
#include "Input.h"
#include "SpriteBatch.h"
#include "SDL_mixer.h"
#include "Sound.h"


namespace SG
{
	//statics
	std::unique_ptr<Graphics>  World::_graphics = nullptr;
	World* World::_instance = nullptr;
	Sound* World::_sound = nullptr;



	World::World(const Point& screenSize)
		: _screenSize(screenSize), _gameWindow(nullptr), _gameClock{std::make_unique<GameClock>()},_input{std::make_unique<Input>()}
	{
		_graphics = std::make_unique<class Graphics>(_screenSize);
		if (_instance == nullptr)
			_instance = this;
	}


	World::~World()
	{
		SDL_DestroyWindow(_gameWindow);
		SDL_Quit();
	}

	bool World::SetupWorldComponents()
	{


		if (!InitializeSdl())
			return false;
		if (!_graphics->Startup())
			return false;
		if (!InitializeSdlMixer())
			return false;
		_input->Startup();
		return true;
	}

	bool World::InitializeSdl()
	{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER | SDL_INIT_TIMER) < 0)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLError);
			return false;
		}
		return true;

	}

	bool World::InitializeSdlMixer() const
	{
		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLMixerError);
			return false;
		}
		_sound = new Sound();
		return true;
	}


	void World::Loop()
	{
		Startup();
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


	bool World::HandleEvents()
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

	void World::HandleInput()
	{
		Input::UpdatePreviousJoystickState();
		HandleEvents();
		Input::UpdateKeyboardStates();
	}


	void World::Draw()
	{

	}
}
