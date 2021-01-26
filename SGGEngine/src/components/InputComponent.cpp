#include "pch.h"
#include "Controller.h"
#include "components/InputComponent.h"

namespace SG
{
	InputComponent::InputComponent(Controller* controller, GameObject* gameObject) : Component(gameObject,SGComponentTypes::Input),CurrentController(controller)
	{
	}

	void InputComponent::TakeControl(SG::Controller* controllerToUse)
	{
		CurrentController = controllerToUse;
	}


}
