////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#ifdef SGGENGINE_EXPORTS
#define SGGENGINE_API __declspec(dllexport)
#else
#define SGGENGINE_API __declspec(dllimport)
#endif
#include <SDL_render.h>
#include <string>
#include "Point.h"

struct SDL_Surface;
struct SDL_Window;
namespace SG
{
	class SGGENGINE_API Graphics
	{
	public:
		Graphics(Point screenSize);
		SDL_Texture* LoadTexture(std::string path);
		bool Startup();
		void Blit(SDL_Surface* thingToBlit);
		void Draw();

		SDL_Texture* ThingToDraw;

	private:

		bool CreateGameWindow();
		bool InitializeSdlPng();
		bool CreateRenderer();


	private:
		Point _screenSize;
		SDL_Window* _gameWindow{};
		SDL_Surface* _windowSurface;
		SDL_Renderer* _renderer;

	};
}
