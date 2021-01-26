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
	class GameObject;

	enum class SGComponentTypes
	{
		Default,
		Image,
		Input
	};

	struct SGGENGINE_API Component
	{
		Component(GameObject* gameObject);
		Component(GameObject* gameObject, SGComponentTypes componentType);

		virtual ~Component() = default;
		virtual void Startup();

		SGComponentTypes ComponentType() const
		{
			return _componentType;
		}

	protected:
		GameObject* _gameObject;
		SGComponentTypes _componentType;
	};
}
