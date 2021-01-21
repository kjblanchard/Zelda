#include "pch.h"

#include "components/Component.h"

namespace SG
{
	Component::Component()
		:_componentType(ComponentTypes::Default)
	{
	}

	void Component::Startup()
	{
	}
}
