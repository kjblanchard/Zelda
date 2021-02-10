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
#include <SDL_rect.h>


#include "GameObject.h"
#include "components/Component.h"
#include "interfaces/IUpdate.h"

namespace SG
{
	class SpriteBatch;

	class SGGENGINE_API BoxColliderComponent : public Component, public IUpdate
	{
	public:
		BoxColliderComponent(GameObject* _gameObject, SDL_Rect offsetAndSize);

		int GetOwnerId() const
		{
			return _gameObject->Id;
		}

		void Startup() override;
		void Update(const double& deltaTime) override;
		void Draw(SpriteBatch& spriteBatch) override;

		virtual bool IsCollision(const SDL_Rect& otherCollider);
		virtual bool IsCollision(const SDL_Rect& potentialMoveRect, const SDL_Rect& otherCollider);

		
		SDL_Rect ColliderBox;

	private:
		int xOffset = 0;
		int yOffset = 0;

		int xSizeOffset = 0;
		int ySizeOffset = 0;


	};
}