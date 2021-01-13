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


namespace SG
{
	//statics
	std::unique_ptr<Graphics>  World::_graphics = nullptr;
	World* World::_instance = nullptr;



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
		_input->Startup();
		return true;
	}

	bool World::InitializeSdl()
	{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) < 0)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLError);
			return false;
		}
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
					_gameObjectList->GameObjectStartup();
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
		if(!_gameObjectList->_gameObjectList.empty())
		{
			auto spriteBatch = SpriteBatch();
			for (auto && gameObject : _gameObjectList->_gameObjectList)
			{
				gameObject->Draw(spriteBatch);
			}
			_graphics->Draw(spriteBatch);
		}
	}
}
