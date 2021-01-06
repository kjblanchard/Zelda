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

namespace SG
{
	enum class ComponentTypes
	{
		Default,
		Image
	};

	struct SGGENGINE_API Component
	{
		Component();
		virtual ~Component() = default;


		ComponentTypes _componentType;
	};
}
