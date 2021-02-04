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
#include "GameObject.h"
#include "components/ImageComponent.h"

namespace SG
{
	template <class T, class F>
	class AnimationComponent :  Component
	{

	public:
		AnimationComponent(GameObject* gameObject);
		~AnimationComponent();
		void Startup() override;
		void Update(const double& deltaTime);
		void Draw(SpriteBatch& spriteBatch);
		T* AnimationController;
		void ChangeAnimation(F whatToChangeTo);

		bool IsAnimPlaying;
	};

	template <class T, class F>
	AnimationComponent<T, F>::AnimationComponent(GameObject* gameObject) :
		Component(gameObject, SGComponentTypes::Animation), AnimationController(nullptr), IsAnimPlaying(false)
	{
	}

	template <class T, class F>
	AnimationComponent<T, F>::~AnimationComponent()
	{
		delete AnimationController;
	}

	template <typename T, typename F>

	void AnimationComponent<T, F>::Startup()
	{
		AnimationController->Startup();
	}

	template <typename T, typename F>

	void AnimationComponent<T, F>::Update(const double& deltaTime)
	{
		if (IsAnimPlaying)
			AnimationController->Update(deltaTime);
		if (_gameObject)
		{
			AnimationController->ImageComponent->UpdateSpriteDestinationInWorld(_gameObject->Location());
		}
	}

	template <typename T, typename F>

	void AnimationComponent<T, F>::Draw(SpriteBatch& spriteBatch)
	{
		AnimationController->Draw(spriteBatch);
	}

	template <typename T, typename F>

	void AnimationComponent<T, F>::ChangeAnimation(F whatToChangeTo)
	{

		AnimationController->ChangeAnimation(whatToChangeTo);
	}

}
