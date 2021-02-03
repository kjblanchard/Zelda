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

namespace SG
{
	class ImageComponent;
	class GameObject;

	template<typename T>
	class AnimationController : public IUpdate
	{
	public:
		AnimationController(GameObject* gameObject = nullptr) : GameObject(gameObject), CurrentAnimation(nullptr) {  }
		virtual ~AnimationController() = default;
		GameObject* GameObject;

		void ChangeAnimation(T animationEnum)
		{
			if (CurrentAnimation != nullptr)
			{
				if(CurrentAnimation->AnimationEnumType == animationEnum)
					return;
				CurrentAnimation->End();
			}

			for (int i = 0; i < Animations.size(); ++i)
			{
				if (Animations[i].AnimationEnumType == animationEnum)
				{
					CurrentAnimation = &Animations[i];
					break;
				}
			}
			if (CurrentAnimation)
				CurrentAnimation->Startup();
			else
				DebugHandler::PrintErrorMessage(ErrorCodes::AnimationError);
		}


		inline const static double FrameTime = 1000.00 / 60;

		static std::vector<Animation<T>> Animations;

		Animation<T>* CurrentAnimation = nullptr;

		int CurrentFrameOnThisSprite = 0;
		int CurrentFrameInAnimation = 0;
		int CurrentTotalAnimationFrames = 0;
		double TimeOnCurrentFrame = 0.0;

		bool staticsInitialized = false;
		ImageComponent* ImageComponent;

	};

}
