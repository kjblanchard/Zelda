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
#include "data/Vector3.h"

namespace SG
{
	class Image;
	class SpriteBatch;
	class GameObject;

	class SGGENGINE_API ImageComponent : public Component
	{
	public:
		/// <summary>
		/// These two constructors are for static images that will not be controlled by the animation controller, they will need a spritesheet
		/// </summary>
		/// <param name="spriteSheetToLoad"></param>
		/// <param name="spriteSheetLocationAndSize"></param>
		/// <param name="gameObject"></param>
		ImageComponent(SpriteSheetEnum spriteSheetToLoad, const SDL_Rect& spriteSheetLocationAndSize, GameObject* gameObject = nullptr);
		ImageComponent(SpriteSheetEnum spriteSheetToLoad, Point imageSize, GameObject* gameObject = nullptr);
		/// <summary>
		/// This is used for animation components
		/// </summary>
		/// <param name="spriteSheetLocationAndSize"></param>
		/// <param name="gameObject"></param>
		ImageComponent(const SDL_Rect& spriteSheetLocationAndSize, GameObject* gameObject = nullptr);
		~ImageComponent();

		void Update(Vector3 location);
		void Draw(SpriteBatch& spritebatch) const;
		/**
		 * \brief Updates the held image's location in the world
		 * \param location The new location of the Image
		 */
		void UpdateSpriteSheetLocation(const Point& locationInSpriteSheet) const;
		void UpdateSpriteDestinationInWorld(const Vector3& worldLocation);

		/// <summary>
		/// Used by the animation controller when changing between animations.
		/// </summary>
		/// <param name="spriteSheet">The new spritesheet that should be placed into the Image class</param>
		void UpdateImageSpriteSheet(Spritesheet* spriteSheet) const;
		std::unique_ptr<Image> image;
	private:
		SG::Vector3 _location;

	};
}
