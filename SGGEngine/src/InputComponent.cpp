#include "pch.h"
#include "Controller.h"
#include  "InputComponent.h"

namespace SG
{


	void InputComponent::TakeControl(SG::Controller* controllerToUse)
	{
		CurrentController = controllerToUse;
	}

	InputComponent::InputComponent(SG::Controller* controller)
	{
		CurrentController = controller;
	}
}
