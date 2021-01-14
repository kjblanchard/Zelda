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
#include <memory>
#include <string>
#include "Component.h"
#include "Point.h"
#include "Vector3.h"

namespace SG
{
	class Image;
	class SpriteBatch;
	class GameObject;

	class SGGENGINE_API ImageComponent : public Component
	{
	public:
		ImageComponent(const std::string& filename, const SDL_Rect& spriteSheetLocationAndSize);
		ImageComponent(const std::string& filename, Point imageSize);
		~ImageComponent();

		void SetLocation(Vector3 location);
		void Update(Vector3 location);

		void Draw(SpriteBatch& spritebatch);

		std::unique_ptr<Image> image;
		SG::Vector3 _location;

	private:

	};
}
