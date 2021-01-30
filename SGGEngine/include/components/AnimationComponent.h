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
#include "animation/AnimationController.h"
#include "components/ImageComponent.h"

namespace SG
{
	template <typename T>
	class AnimationComponent :  Component
	{

	public:

		AnimationComponent(GameObject* gameObject);

		void Startup() override;
		void Update(const double& deltaTime);
		void Draw(SpriteBatch& spriteBatch);
		AnimationController<T> AnimationController;
	};

	template <typename T>
	AnimationComponent<T>::AnimationComponent(GameObject* gameObject) : Component(gameObject, SGComponentTypes::Animation)
	{
	}

	template <typename T>
	void AnimationComponent<T>::Startup()
	{
	}

	template <typename T>
	void AnimationComponent<T>::Update(const double& deltaTime)
	{
		AnimationController.Update(deltaTime);
	}

	template <typename T>
	void AnimationComponent<T>::Draw(SpriteBatch& spriteBatch)
	{
		AnimationController.Draw(spriteBatch);
	}
}
