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
	struct SGGENGINE_API SpriteBatch
	{
	public:
		void AddToSpriteBatch(SDL_Texture* textureToAdd);
		std::vector<SDL_Texture*> GameTextures()
		{
			return _gameTextures;
		}
	private:
		std::vector<SDL_Texture*> _gameTextures;
	};
}
