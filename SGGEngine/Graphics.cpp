#include "pch.h"
#include  "Graphics.h"
#include <SDL_image.h>
#include "Game.h"

namespace SG
{

	Graphics::Graphics(Point screenSize)
		:_screenSize(screenSize), _windowSurface(nullptr)
	{
	}

	SDL_Texture* Graphics::LoadTexture(std::string path)
	{
		auto newPath = "assets/" + path;
		//The final texture
		SDL_Texture* newTexture = NULL;

		//Load image at specified path
		SDL_Surface* loadedSurface = IMG_Load(newPath.c_str());
		if (loadedSurface == NULL)
		{
			printf("Unable to load image %s! SDL_image Error: %s\n", newPath.c_str(), IMG_GetError());
		}
		else
		{
			//Create texture from surface pixels
			newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
			if (newTexture == NULL)
			{
				printf("Unable to create texture from %s! SDL Error: %s\n", newPath.c_str(), SDL_GetError());
			}

			//Get rid of old loaded surface
			SDL_FreeSurface(loadedSurface);
		}

		return newTexture;
	}

	bool Graphics::Startup()
	{
		if (!CreateGameWindow())
			return false;
		if (!InitializeSdlPng())
			return false;
		if (!CreateRenderer())
			return false;
		return true;
	}

	void Graphics::Blit(SDL_Surface* thingToBlit)
	{
		auto blank = thingToBlit;
		SDL_BlitSurface(thingToBlit, NULL, _windowSurface, NULL);
	}

	bool Graphics::CreateGameWindow()
	{
		_gameWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenSize.X, _screenSize.Y, SDL_WINDOW_SHOWN);
		if (_gameWindow)
			return true;
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	void Graphics::Draw()
	{
		//Get window surface
		_windowSurface = SDL_GetWindowSurface(_gameWindow);

		//Fill the surface white
		//SDL_FillRect(_windowSurface, nullptr, SDL_MapRGB(_windowSurface->format, 0xff, 0xFF, 0xFF));

				//Clear screen
		SDL_RenderClear(_renderer);

		//Render texture to screen
		SDL_RenderCopy(_renderer, ThingToDraw, NULL, NULL);

		//Update screen
		SDL_RenderPresent(_renderer);


		//Wait two seconds
		SDL_Delay(3000);
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
