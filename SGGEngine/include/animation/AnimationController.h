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
#include "DebugHandler.h"
#include "GameObject.h"
#include "components/ImageComponent.h"
#include "data/Vector3.h"

namespace SG
{
	class ImageComponent;
	class GameObject;

	template<class T>
	class AnimationController : public IUpdate
	{
	public:
		AnimationController(GameObject* gameObject = nullptr) : _gameObject(gameObject), _currentAnimation(nullptr),
		                                                        _imageComponent(nullptr)
		{
		}
		virtual ~AnimationController() = default;

		void Update(const double& deltaTime) override;
		virtual void ChangeAnimation(T animationEnum);
		void UpdateSpriteLocation(SG::Vector3 location);

	protected:
		inline const static double FrameTime = 1000.00 / 60;
		static std::vector<Animation<T>> Animations;

		GameObject* _gameObject;
		Animation<T>* _currentAnimation = nullptr;
		int _currentFrameOnThisSprite = 0;
		int _currentFrameInAnimation = 0;
		int _currentTotalAnimationFrames = 0;
		double _timeOnCurrentFrame = 0.0;
		bool staticsInitialized = false;
		ImageComponent* _imageComponent;

	};




	template <typename T>
	void AnimationController<T>::ChangeAnimation(T animationEnum)
	{
		if (_currentAnimation != nullptr)
		{
			if (_currentAnimation->AnimationEnumType == animationEnum)
				return;
		}

		for (int i = 0; i < Animations.size(); ++i)
		{
			if (Animations[i].AnimationEnumType == animationEnum)
			{
				_currentAnimation = &Animations[i];
				break;
			}
		}

		if (_currentAnimation == nullptr)
			DebugHandler::PrintErrorMessage(ErrorCodes::AnimationError);
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

		_timeOnCurrentFrame = 0;
	}

	template <class T>
	void AnimationController<T>::UpdateSpriteLocation(SG::Vector3 location)
	{
		_imageComponent->UpdateSpriteDestinationInWorld(location);
	}
}
