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
#include <memory>
#include "Component.h"
#include "Spritesheet.h"
#include "data/Point.h"

namespace SG
{
	class Image;
	class SpriteBatch;
	class GameObject;

	class SGGENGINE_API ImageComponent : public Component
	{
	public:
		ImageComponent(SpriteSheetEnum spriteSheetToLoad, const SDL_Rect& spriteSheetLocationAndSize);
		ImageComponent(SpriteSheetEnum spriteSheetToLoad, Point imageSize);
		~ImageComponent();

		void Update(Vector3 location);
		void Draw(SpriteBatch& spritebatch) const;
		/**
		 * \brief Updates the held image's location in the world
		 * \param location The new location of the Image
		 */
		void SetLocation(Vector3 location);


	private:
		std::unique_ptr<Image> image;
		SG::Vector3 _location;

	};
}