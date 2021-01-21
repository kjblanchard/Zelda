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
#include "Point.h"
#include "Vector3.h"

namespace SG
{
	enum class SpriteSheetEnum;
	class Spritesheet;
	class Graphics;

	class SGGENGINE_API Image
	{


	public:
		Image();
		Image(SpriteSheetEnum spriteSheetToLoad, const SDL_Rect& spriteSheetLocationAndSize);
		Image(SpriteSheetEnum spriteSheetToLoad, Point imageSize);
		void UpdateDestRectLocation(Vector3 location);
		Spritesheet* SpriteSheet;
		Vector3 Location;
		Point Size;
		SDL_Rect LocationAndSizeInSpriteSheet;
		SDL_Rect LocationAndSizeOnRenderer;
		bool ImageIsWholeTexture = false;
	private:
		static Spritesheet* GenerateImage(SpriteSheetEnum spriteSheetToLoad);
		static Graphics* _graphics;
	};
}
