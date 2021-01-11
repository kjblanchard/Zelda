#include "pch.h"
#include "Game.h"
#include <iostream>
#include <SDL.h>
#include "DebugHandler.h"
#include "GameClock.h"
#include "GameObject.h"
#include "Graphics.h"
#include "Input.h"
#include "SpriteBatch.h"


namespace SG
{
	//statics
	std::unique_ptr<Graphics>  Game::_graphics = nullptr;
	Game* Game::_instance = nullptr;
	std::vector<std::unique_ptr<GameObject>> Game::_gameObjectList;
	std::vector<std::unique_ptr<GameObject>> Game::_gameObjectStartupList;




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
					GameObjectStartup();
					HandleInput();
					Update(_gameClock->MsPerFrame());
					_gameClock->UpdateClockTimer();
				}
				Draw();
			}
		}
	}

	void Game::AddToGameObjectList(std::unique_ptr<GameObject> gameObject)
	{
		_gameObjectStartupList.push_back(std::move(gameObject));

	}

	void Game::GameObjectStartup()
	{
		if (!_gameObjectStartupList.empty())
		{
			for (auto&& gameObjectStartupList : _gameObjectStartupList)
			{
				gameObjectStartupList->Startup();

			}
			for (auto&& gameObject : _gameObjectStartupList)
			{
				_gameObjectList.push_back(std::move(gameObject));
			}
		}
		_gameObjectStartupList.clear();


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
		if(!_gameObjectList.empty())
		{
			for (auto && gameObject : _gameObjectList)
			{
				gameObject->Update();
			}
		}
	}

	void Game::Draw()
	{
		if(!_gameObjectList.empty())
		{
			auto spriteBatch = SpriteBatch();
			for (auto && gameObject : _gameObjectList)
			{
				gameObject->Draw(spriteBatch);
			}
			_graphics->Draw(spriteBatch);
		}
	}
}
