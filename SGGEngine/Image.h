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

namespace SG
{
	class Graphics;

	class SGGENGINE_API Image
	{


	public:
		Image();
		Image(const std::string& filename, const SDL_Rect& spriteSheetLocationAndSize);
		Image(const std::string& filename, Point imageSize);
		~Image();

		static Graphics* _graphics;
		SDL_Texture* _imageTexture;
		Point Location;
		Point Size;
		SDL_Rect LocationAndSizeInSpriteSheet;
	private:
		SDL_Texture* GenerateImage(const std::string& filename);
	};
}
