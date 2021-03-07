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
#include "core/GameObject.h"
#include "components/ImageComponent.h"
#include "AnimationComponent.h"
#include "animation/AnimationController.h"

namespace SG
{
	template <class T, class F>
	class AnimationComponent :  Component
	{
	public:
		AnimationComponent(GameObject* gameObject, T* animController);
		~AnimationComponent();
		void Startup() override;
		void Update(const double& deltaTime);
		void Draw(SpriteBatch& spriteBatch);
		void ChangeAnimation(F whatToChangeTo);
		bool IsAnimPlaying = true;
		//TODO move this back to private
		T* _animationController;
	private:

	};

	template <class T, class F>
	AnimationComponent<T, F>::AnimationComponent(GameObject* gameObject, T* animController) : Component(gameObject, SGComponentTypes::Animation), IsAnimPlaying(false), _animationController(animController)
	{
	}

	template <class T, class F>
	AnimationComponent<T, F>::~AnimationComponent()
	{
		delete _animationController;
	}

	template <typename T, typename F>

	void AnimationComponent<T, F>::Startup()
	{
		_animationController->Startup();
	}

	template <typename T, typename F>

	void AnimationComponent<T, F>::Update(const double& deltaTime)
	{
		if (IsAnimPlaying)
			_animationController->Update(deltaTime);
	}

	template <typename T, typename F>

	void AnimationComponent<T, F>::Draw(SpriteBatch& spriteBatch)
	{
		_animationController->Draw(spriteBatch);
	}

	template <typename T, typename F>

	void AnimationComponent<T, F>::ChangeAnimation(F whatToChangeTo)
	{

		_animationController->ChangeAnimation(whatToChangeTo);
	}

}
