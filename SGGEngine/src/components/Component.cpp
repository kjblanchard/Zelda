#include "pch.h"
#include "components/Component.h"
#include "core/GameObject.h"

namespace SG
{

	Component::Component(GameObject* gameObject): _gameObject(gameObject), _componentType(SGComponentTypes::Default)
	{
		if (gameObject)
			gameObject->AddComponent(this);
	}

	Component::Component(GameObject* gameObject, SGComponentTypes componentType): _gameObject(gameObject), _componentType(componentType)
	{
		if (gameObject)
			gameObject->AddComponent(this);
	}
}
