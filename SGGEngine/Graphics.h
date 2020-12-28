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
#include <string>
#include "Point.h"

struct SDL_Texture;
struct SDL_Surface;
struct SDL_Window;
struct SDL_Renderer;

namespace SG
{
	class SpriteBatch;

	class SGGENGINE_API Graphics
	{
	public:
		Graphics(Point screenSize);


		bool Startup();
		void Draw(SpriteBatch& spriteBatch );

		/**
		 * \brief Loads a surface from a file, and converts that into a texture for use in displaying things on screen
		 * \param fileName The filename, this file should be in the assets/graphics folder
		 * \return Returns a texture if the file is found, otherwise returns a nullptr
		 */
		SDL_Texture* LoadTexture(std::string fileName) const;
	private:

		bool CreateGameWindow();
		static bool InitializeSdlImg();
		bool CreateRenderer();


	private:
		Point _screenSize;
		SDL_Window* _gameWindow{};
		SDL_Surface* _windowSurface;
		SDL_Renderer* _renderer;

	};
}
