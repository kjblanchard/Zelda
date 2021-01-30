#include "Link.h"
#include "PlayerController.h"
#include "components/InputComponent.h"
#include "components/AnimationComponent.h"
#include "data/Vector3.h"


Link::Link(SG::Vector3 location)
	: GameObject(location), _animationComponent(nullptr),_inputComponent(nullptr)
{
}

Link::Link(SG::Vector3 location, SG::Controller* controller)
	:Link(location)
{
	_inputComponent = std::make_unique<SG::InputComponent>(controller, this);
}

Link::~Link()
{
}


void Link::Startup()
{
	_animationComponent = new SG::AnimationComponent<LinkAnimations>(this);
	_animationComponent->Startup();
}

void Link::Update(const double& deltaTime)
{
	HandleInput();
	ComponentUpdate();
	_animationComponent->Update(deltaTime);
}

void Link::Draw(SG::SpriteBatch& spriteBatch)
{
	_animationComponent->Draw(spriteBatch);

}


void Link::ComponentUpdate()
{
}

void Link::HandleInput()
{
	if(_inputComponent)
	{
		if(_inputComponent->CurrentController)
		{
			SG::ControllerButtons button = SG::ControllerButtons::Up;
			if (_inputComponent->CurrentController->IsButtonPressed(button) || _inputComponent->CurrentController->IsButtonHeld(button))
			{
				_location.Y--;
			}
			button = SG::ControllerButtons::Down;
			if (_inputComponent->CurrentController->IsButtonPressed(button) || _inputComponent->CurrentController->IsButtonHeld(button))
			{
				_location.Y++;

			}
			button = SG::ControllerButtons::Left;
			if (_inputComponent->CurrentController->IsButtonPressed(button) || _inputComponent->CurrentController->IsButtonHeld(button))
			{
				_location.X--;
			}
			button = SG::ControllerButtons::Right;
			if (_inputComponent->CurrentController->IsButtonPressed(button) || _inputComponent->CurrentController->IsButtonHeld(button))
			{
				_location.X++;
			}


		}
	}
}
