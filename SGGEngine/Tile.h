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
#include <memory>

#include "GameObject.h"

namespace SG
{
	class ImageComponent;

	class SGGENGINE_API Tile : public GameObject
	{
	public:
		Tile();
		Tile(Vector3 location);
		~Tile();

		void Startup() override;
		void Draw(SpriteBatch& spriteBatch) override;

		std::unique_ptr<ImageComponent> _imageComponent;

	};
}
