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
#include "Component.h"
#include "Point.h"

namespace SG
{
	class GameObject;

	class SGGENGINE_API ImageComponent : public Component
	{
	public:
		ImageComponent(GameObject* owner);
		~ImageComponent();

		Point TextureDimensions;
		GameObject* _owner;
		SDL_Texture* Texture;

	private:
		void DeleteTexture(SDL_Texture* textureToDestroy)
		{
			SDL_DestroyTexture(textureToDestroy);
		}
	};
}
