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
#include "Animation.h"
#include "interfaces/IUpdate.h"
#include "core/DebugHandler.h"
#include "core/GameObject.h"
#include "components/ImageComponent.h"
#include "data/Vector3.h"
#include "core/Configuration.h"

namespace SG
{
	class ImageComponent;
	class GameObject;

	/// <summary>
	/// This should be the base class for all animation controllers in the game.  An animation controller should be made for everything that needs animation.
	/// </summary>
	/// <typeparam name="T">The enum that should be used for switching animations in this controller</typeparam>
	template<class T>
	class AnimationController : public IUpdate
	{
	public:
		/// <summary>
		/// This should be the base class for all animation controllers in the game.  An animation controller should be made for everything that needs animation.
		/// </summary>
		/// <param name="gameObject">The owner of this animation controller</param>
		AnimationController(GameObject* gameObject) : _gameObject(gameObject), _currentAnimation(nullptr),
		                                                        _imageComponent(nullptr)
		{
		}
		virtual ~AnimationController() = default;

		void Startup() override;
		void Update(const double& deltaTime) override;
		virtual void ChangeAnimation(T animationEnum);

		/// <summary>
		/// Updates the current location of the sprite
		/// </summary>
		/// <param name="location"></param>
		void UpdateSpriteLocation(SG::Vector3 location);
		//TODO movet his back to protected
		ImageComponent* _imageComponent;
	protected:
		inline const static double FrameTime = Configuration::BaseConfigurationSettings.FrameTime ;
		static std::vector<Animation<T>> Animations;
		GameObject* _gameObject;

		Animation<T>* _currentAnimation = nullptr;
		int _currentFrameOnThisSprite = 0;
		int _currentFrameInAnimation = 0;
		int _currentTotalAnimationFrames = 0;
		double _timeOnCurrentFrame = 0.0;
		bool staticsInitialized = false;

	};




	template <typename T>
	void AnimationController<T>::ChangeAnimation(T animationEnum)
	{
		if (_currentAnimation != nullptr)
		{
			if (_currentAnimation->AnimationEnumType == animationEnum)
				return;
		}

		for (unsigned int i = 0; i < Animations.size(); ++i)
		{
			if (Animations[i].AnimationEnumType == animationEnum)
			{
				_currentAnimation = &Animations[i];
				_imageComponent->UpdateImageSpriteSheet(_currentAnimation->SpriteSheet);
				//_imageComponent->UpdateSpriteSheetLocation(_currentAnimation->DrawLocation(_currentFrameOnThisSprite));
				break;
			}
		}

		if (_currentAnimation == nullptr)
			DebugHandler::PrintErrorMessage(ErrorCodes::AnimationError);
	}

	template <class T>
	void AnimationController<T>::Startup()
	{
		UpdateSpriteLocation(_gameObject->Location());
	}

	template <class T>
	void AnimationController<T>::Update(const double& deltaTime)
	{
		_timeOnCurrentFrame += deltaTime;
		if (_timeOnCurrentFrame >= FrameTime)
		{
			auto desiredFrame = _currentFrameInAnimation + 1;
			_currentFrameInAnimation++;
			if (desiredFrame > _currentAnimation->LocationAndLengthOfAnimation[_currentFrameOnThisSprite].second)
			{
				desiredFrame = _currentFrameOnThisSprite + 1;
				if (desiredFrame >= _currentAnimation->TotalAnimationFrames())
				{
					_currentFrameOnThisSprite = 0;
					_currentFrameInAnimation = 0;
				}
				else
				{
					++_currentFrameOnThisSprite;
					_currentFrameInAnimation = 0;
				}
			}
		}
		else
		{
			_currentFrameInAnimation = 0;
		}
		UpdateSpriteLocation(_gameObject->Location());
	}

	template <class T>
	void AnimationController<T>::UpdateSpriteLocation(SG::Vector3 location)
	{
		_imageComponent->Update(location);
	}
}
