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
#include <vector>

namespace SG
{
	class Image;

	class SGGENGINE_API SpriteBatch
	{
	public:
		void AddToSpriteBatch(Image* imageToDraw);
		std::vector<Image*> GameTextures()
		{
			return _gameTextures;
		}
	private:
		std::vector<Image*> _gameTextures;
	};
}
