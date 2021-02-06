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
#include "components/Component.h"

namespace SG
{
	class SGGENGINE_API BoxCollider : public Component
	{
		BoxCollider(GameObject* gameObject) : Component(gameObject,SGComponentTypes); 
	};
}
