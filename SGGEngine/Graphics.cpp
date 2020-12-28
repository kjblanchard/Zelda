#include "pch.h"
#include  "Graphics.h"
#include <SDL_image.h>

#include "DebugHandler.h"

namespace SG
{

	Graphics::Graphics(Point screenSize)
		:_screenSize(screenSize), _windowSurface(nullptr)
	{
	}

	bool Graphics::Startup()
	{
		if (!CreateGameWindow())
			return false;
		if (!InitializeSdlPng())
			return false;
		if (!CreateRenderer())
			return false;
		_windowSurface = SDL_GetWindowSurface(_gameWindow);
		return true;
	}

	void Graphics::Draw(SpriteBatch& spriteBatch)
	{
		SDL_RenderClear(_renderer);
		for (auto sprite : spriteBatch.GameTextures())
		{
			SDL_RenderCopy(_renderer, sprite, NULL, NULL);
		}
		SDL_RenderPresent(_renderer);
		SDL_Delay(3000);
	}

	SDL_Texture* Graphics::LoadTexture(std::string fileName)
	{
		fileName.insert(0, "assets/graphics/");
		SDL_Texture* newTexture = nullptr;
		SDL_Surface* loadedSurface = IMG_Load(fileName.c_str());
		if (loadedSurface)
		{
			newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
			if (newTexture)
			{
				SDL_FreeSurface(loadedSurface);
			}
			else
				DebugHandler::PrintErrorMessage(ErrorCodes::SDLTextureError);

		}
		else
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLImageError);
		return newTexture;
	}

	bool Graphics::CreateGameWindow()
	{
		_gameWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenSize.X, _screenSize.Y, SDL_WINDOW_SHOWN);
		if (_gameWindow)
			return true;
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}


	bool Graphics::InitializeSdlPng()
	{
		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			return false;
		}
		printf("Initialized png");
		return true;
	}

	bool Graphics::CreateRenderer()
	{
		//Create renderer for window
		_renderer = SDL_CreateRenderer(_gameWindow, -1, SDL_RENDERER_ACCELERATED);
		if (_renderer == NULL)
		{
			printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
			return false;
		}
		else
		{
			//Initialize renderer color
			SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			return true;
		}
	}
}

#include "Game.h"