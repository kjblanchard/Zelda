#include "pch.h"

#include "components/Component.h"

namespace SG
{

	Component::Component(GameObject* gameObject): _gameObject(gameObject), _componentType(SGComponentTypes::Default)
	{
	}

	Component::Component(GameObject* gameObject, SGComponentTypes componentType): _gameObject(gameObject), _componentType(componentType)
	{
	}

	void Component::Startup()
	{
	}
}
