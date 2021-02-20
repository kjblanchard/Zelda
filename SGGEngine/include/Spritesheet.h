﻿////////////////////////////////////////////////////////////
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
#include <memory>

namespace SG
{
	enum class SpriteSheetEnum
	{
		Default = 0,
		TileSet = 1,
		Link = 2,
		LinkWalking = 3,
		LinkAttacking = 4,
		WoodSword = 5,


	};

	class SGGENGINE_API Spritesheet
	{
	public:
		Spritesheet(std::string fileName);
		~Spritesheet()
		{
			SDL_DestroyTexture(SpriteSheetTexture);
		}

		SDL_Texture* SpriteSheetTexture = nullptr;
		const std::string FileName;
		bool IsLoaded = false;
	};
}
