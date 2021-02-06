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
#include <SDL_rect.h>

#include "components/Component.h"
#include "interfaces/IUpdate.h"

namespace SG
{
	class SpriteBatch;

	class SGGENGINE_API BoxColliderComponent : public Component, public IUpdate
	{
	public:
		BoxColliderComponent(GameObject* _gameObject);

		void Startup() override;
		void Update(const double& deltaTime) override;
		void Draw(SpriteBatch& spriteBatch) override;

		virtual bool IsCollision(const SDL_Rect& otherCollider);
		virtual bool IsCollision(const SDL_Rect& potentialMoveRect, const SDL_Rect& otherCollider);

		SDL_Rect ColliderBox;

	};
}
