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
#include "animation/Animation.h"
#include "components/ImageComponent.h"

namespace SG
{
	class SGGENGINE_API AnimationComponent : Component
	{

	public:

		AnimationComponent(GameObject* gameObject);

		void Startup() override;
		void Update(const double& deltaTime);
		void Draw(SpriteBatch& spriteBatch);

		ImageComponent* _imageComponent;
		int _currentFrameInAnimation = 0;
		Animation _currentAnimation;
	};
}
