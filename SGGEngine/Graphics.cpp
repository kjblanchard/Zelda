#include "pch.h"
#include  "Graphics.h"
#include <SDL_image.h>
#include "DebugHandler.h"
#include "Image.h"
#include "SpriteBatch.h"


namespace SG
{

	Graphics::Graphics(Point screenSize)
		: _screenSize(screenSize), _windowSurface(nullptr), _renderer(nullptr)
	{
	}

	bool Graphics::Startup()
	{
		if (!CreateGameWindow())
			return false;
		if (!InitializeSdlImg())
			return false;
		if (!CreateRenderer())
			return false;
		return true;
	}

	bool Graphics::CreateGameWindow()
	{
		_gameWindow = SDL_CreateWindow("Zelda - KJB", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenSize.X, _screenSize.Y, SDL_WINDOW_SHOWN);
		if (!_gameWindow)
		{
			SG::DebugHandler::PrintErrorMessage(ErrorCodes::WindowError);
			return false;
		}
		_windowSurface = SDL_GetWindowSurface(_gameWindow);
		if(!_windowSurface)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLError);
			return false;
		}
		return true;
	}

	bool Graphics::InitializeSdlImg()
	{
		const int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLImageError);
			return false;
		}
		return true;
	}

	bool Graphics::CreateRenderer()
	{
		_renderer = SDL_CreateRenderer(_gameWindow, -1, SDL_RENDERER_ACCELERATED);
		if (!_renderer)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLError);
			return false;
		}
		SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, 0x00);
		return true;
	}

	void Graphics::Draw(SpriteBatch& spriteBatch)
	{
		SDL_RenderClear(_renderer);
		for (auto* sprite : spriteBatch.GameTextures())
		{
			SDL_RenderCopy(_renderer, sprite->_imageTexture, NULL, NULL);
		}
		SDL_RenderPresent(_renderer);
		SDL_Delay(3000);
	}

	SDL_Texture* Graphics::LoadTexture(std::string fileName) const
	{
		fileName.insert(0, "assets/graphics/");
		SDL_Texture* newTexture = nullptr;
		SDL_Surface* loadedSurface = IMG_Load(fileName.c_str());
		if(!loadedSurface)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLImageError);
			return newTexture;
		}
		newTexture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
		if(!newTexture)
		{
			DebugHandler::PrintErrorMessage(ErrorCodes::SDLTextureError);
			return newTexture;
		}
		SDL_FreeSurface(loadedSurface);
		return newTexture;
	}

}

#include "Game.h"