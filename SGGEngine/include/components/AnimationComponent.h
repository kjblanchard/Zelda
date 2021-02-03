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
	template <typename T, typename F>
	class AnimationComponent :  Component
	{

	public:
		AnimationComponent() = default;
		AnimationComponent(GameObject* gameObject);

		void Startup() override;
		void Update(const double& deltaTime);
		void Draw(SpriteBatch& spriteBatch);
		T AnimationController;
		void ChangeAnimation(F whatToChangeTo);

		bool IsAnimPlaying;
	};

	template <typename T, typename F>
	AnimationComponent<T, F>::AnimationComponent(GameObject* gameObject) : Component(gameObject, SGComponentTypes::Animation)
	{
	}
	template <typename T, typename F>

	void AnimationComponent<T, F>::Startup()
	{
	}

	template <typename T, typename F>

	void AnimationComponent<T, F>::Update(const double& deltaTime)
	{
		if(IsAnimPlaying)
			AnimationController.Update(deltaTime);
	}

	template <typename T, typename F>

	void AnimationComponent<T, F>::Draw(SpriteBatch& spriteBatch)
	{
		AnimationController.Draw(spriteBatch);
	}

	template <typename T, typename F>

	void AnimationComponent<T, F>::ChangeAnimation(F whatToChangeTo)
	{

		AnimationController.ChangeAnimation(whatToChangeTo);
	}
}
