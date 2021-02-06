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
		void AddToSpriteBatch(SDL_Rect* debugBoxToDraw);
		std::vector<Image*> GameTextures() const
		{
			return _gameTextures;
		}
		std::vector<SDL_Rect*> DebugBoxes() const
		{
			return _debugBoxes;
		}


		void ClearSpriteBatch() { _gameTextures.clear(); }
	private:
		std::vector<Image*> _gameTextures;
		std::vector<SDL_Rect*> _debugBoxes;
	};
}
