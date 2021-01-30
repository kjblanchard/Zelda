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

namespace SG
{
	class GameObject;

	template <typename T>
	class SGGENGINE_API AnimationController : public IUpdate
	{
	public:
		AnimationController(GameObject* gameObject = nullptr) : GameObject(gameObject) {  }
		virtual ~AnimationController() = default;
		GameObject* GameObject;

		virtual void ChangeAnimation(T animationEnum) = 0;


		inline const static double FrameTime = 1000.00 / 60;

		int CurrentFrame = 0;
		double TimeOnCurrentFrame = 0.0;


	};
}
