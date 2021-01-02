#include "pch.h"


#include  "PlayerController.h"

#include "Input.h"

namespace SG
{
	bool PlayerController::IsButtonPressed(ControllerButtons controllerButton)
	{
		switch (controllerButton) {
		case ControllerButtons::Default:
			return false;
		case ControllerButtons::Up:
			return Input::KeyJustPressed(_controllerMapping->UpButton);
		case ControllerButtons::Right:
			return Input::KeyJustPressed(_controllerMapping->RightButton);
		case ControllerButtons::Down:
			return Input::KeyJustPressed(_controllerMapping->DownButton);
		case ControllerButtons::Left:
			return Input::KeyJustPressed(_controllerMapping->LeftButton);
		case ControllerButtons::Y:
			return Input::KeyJustPressed(_controllerMapping->YButton);
		case ControllerButtons::B:
			return Input::KeyJustPressed(_controllerMapping->BButton);
		case ControllerButtons::A:
			return Input::KeyJustPressed(_controllerMapping->AButton);
		case ControllerButtons::X:
			return Input::KeyJustPressed(_controllerMapping->XButton);
		case ControllerButtons::Start:
			return Input::KeyJustPressed(_controllerMapping->StartButton);
		case ControllerButtons::Select:
			return Input::KeyJustPressed(_controllerMapping->SelectButton);
		}
		return false;
	}

	bool PlayerController::IsButtonHeld(ControllerButtons controllerButton)
	{
		switch (controllerButton) {
		case ControllerButtons::Default:
			return false;
		case ControllerButtons::Up:
			return Input::IsKeyHeldDown(_controllerMapping->UpButton);
		case ControllerButtons::Right:
			return Input::IsKeyHeldDown(_controllerMapping->RightButton);
		case ControllerButtons::Down:
			return Input::IsKeyHeldDown(_controllerMapping->DownButton);
		case ControllerButtons::Left:
			return Input::IsKeyHeldDown(_controllerMapping->LeftButton);
		case ControllerButtons::Y:
			return Input::IsKeyHeldDown(_controllerMapping->YButton);
		case ControllerButtons::B:
			return Input::IsKeyHeldDown(_controllerMapping->BButton);
		case ControllerButtons::A:
			return Input::IsKeyHeldDown(_controllerMapping->AButton);
		case ControllerButtons::X:
			return Input::IsKeyHeldDown(_controllerMapping->XButton);
		case ControllerButtons::Start:
			return Input::IsKeyHeldDown(_controllerMapping->StartButton);
		case ControllerButtons::Select:
			return Input::IsKeyHeldDown(_controllerMapping->SelectButton);
		}
		return false;
	}

	bool PlayerController::IsButtonReleased(ControllerButtons controllerButton)
	{
		switch (controllerButton) {
		case ControllerButtons::Default:
			return false;
		case ControllerButtons::Up:
			return Input::KeyJustReleased(_controllerMapping->UpButton);
		case ControllerButtons::Right:
			return Input::KeyJustReleased(_controllerMapping->RightButton);
		case ControllerButtons::Down:
			return Input::KeyJustReleased(_controllerMapping->DownButton);
		case ControllerButtons::Left:
			return Input::KeyJustReleased(_controllerMapping->LeftButton);
		case ControllerButtons::Y:
			return Input::KeyJustReleased(_controllerMapping->YButton);
		case ControllerButtons::B:
			return Input::KeyJustReleased(_controllerMapping->BButton);
		case ControllerButtons::A:
			return Input::KeyJustReleased(_controllerMapping->AButton);
		case ControllerButtons::X:
			return Input::KeyJustReleased(_controllerMapping->XButton);
		case ControllerButtons::Start:
			return Input::KeyJustReleased(_controllerMapping->StartButton);
		case ControllerButtons::Select:
			return Input::KeyJustReleased(_controllerMapping->SelectButton);
		}
		return false;
	}
}
