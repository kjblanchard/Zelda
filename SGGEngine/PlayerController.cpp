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
			return Input::KeyJustPressed(_keyboardMapping.UpButton) || Input::KeyJustPressed (_playerNum,_joystickMapping.UpButton);
		case ControllerButtons::Right:
			return Input::KeyJustPressed(_keyboardMapping.RightButton) || Input::KeyJustPressed(_playerNum, _joystickMapping.RightButton);
		case ControllerButtons::Down:
			return Input::KeyJustPressed(_keyboardMapping.DownButton) || Input::KeyJustPressed(_playerNum, _joystickMapping.DownButton);
		case ControllerButtons::Left:
			return Input::KeyJustPressed(_keyboardMapping.LeftButton) || Input::KeyJustPressed(_playerNum, _joystickMapping.LeftButton);
		case ControllerButtons::Y:
			return Input::KeyJustPressed(_keyboardMapping.YButton) || Input::KeyJustPressed(_playerNum, _joystickMapping.YButton);
		case ControllerButtons::B:
			return Input::KeyJustPressed(_keyboardMapping.BButton) || Input::KeyJustPressed(_playerNum, _joystickMapping.BButton);
		case ControllerButtons::A:
			if (Input::KeyJustPressed(_keyboardMapping.AButton))
				return true;
			if (Input::KeyJustPressed(_playerNum, _joystickMapping.AButton))
				return true;
			return false;
			//return ((Input::KeyJustPressed(_keyboardMapping.AButton)) || (Input::KeyJustPressed(_playerNum, _joystickMapping.AButton)));
		case ControllerButtons::X:
			return Input::KeyJustPressed(_keyboardMapping.XButton) || Input::KeyJustPressed(_playerNum, _joystickMapping.XButton);
		case ControllerButtons::Start:
			return Input::KeyJustPressed(_keyboardMapping.StartButton) || Input::KeyJustPressed(_playerNum, _joystickMapping.StartButton);
		case ControllerButtons::Select:
			return Input::KeyJustPressed(_keyboardMapping.SelectButton) || Input::KeyJustPressed(_playerNum, _joystickMapping.SelectButton);
		}
		return false;
	}

	bool PlayerController::IsButtonHeld(ControllerButtons controllerButton)
	{
		//switch (controllerButton) {
		//case ControllerButtons::Default:
		//	return false;
		//case ControllerButtons::Up:
		//	return Input::IsKeyHeldDown(_controllerMapping->UpButton);
		//case ControllerButtons::Right:
		//	return Input::IsKeyHeldDown(_controllerMapping->RightButton);
		//case ControllerButtons::Down:
		//	return Input::IsKeyHeldDown(_controllerMapping->DownButton);
		//case ControllerButtons::Left:
		//	return Input::IsKeyHeldDown(_controllerMapping->LeftButton);
		//case ControllerButtons::Y:
		//	return Input::IsKeyHeldDown(_controllerMapping->YButton);
		//case ControllerButtons::B:
		//	return Input::IsKeyHeldDown(_controllerMapping->BButton);
		//case ControllerButtons::A:
		//	return Input::IsKeyHeldDown(_controllerMapping->AButton);
		//case ControllerButtons::X:
		//	return Input::IsKeyHeldDown(_controllerMapping->XButton);
		//case ControllerButtons::Start:
		//	return Input::IsKeyHeldDown(_controllerMapping->StartButton);
		//case ControllerButtons::Select:
		//	return Input::IsKeyHeldDown(_controllerMapping->SelectButton);
		//}
		return false;
	}

	bool PlayerController::IsButtonReleased(ControllerButtons controllerButton)
	{
		//switch (controllerButton) {
		//case ControllerButtons::Default:
		//	return false;
		//case ControllerButtons::Up:
		//	return Input::KeyJustReleased(_controllerMapping->UpButton);
		//case ControllerButtons::Right:
		//	return Input::KeyJustReleased(_controllerMapping->RightButton);
		//case ControllerButtons::Down:
		//	return Input::KeyJustReleased(_controllerMapping->DownButton);
		//case ControllerButtons::Left:
		//	return Input::KeyJustReleased(_controllerMapping->LeftButton);
		//case ControllerButtons::Y:
		//	return Input::KeyJustReleased(_controllerMapping->YButton);
		//case ControllerButtons::B:
		//	return Input::KeyJustReleased(_controllerMapping->BButton);
		//case ControllerButtons::A:
		//	return Input::KeyJustReleased(_controllerMapping->AButton);
		//case ControllerButtons::X:
		//	return Input::KeyJustReleased(_controllerMapping->XButton);
		//case ControllerButtons::Start:
		//	return Input::KeyJustReleased(_controllerMapping->StartButton);
		//case ControllerButtons::Select:
		//	return Input::KeyJustReleased(_controllerMapping->SelectButton);
		//}
		return false;
	}
}
