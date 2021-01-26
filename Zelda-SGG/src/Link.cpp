﻿#include "Link.h"
#include "PlayerController.h"
#include "components/ImageComponent.h"
#include "components/InputComponent.h"
#include "Spritesheet.h"
#include "data/Point.h"
#include "data/Vector3.h"


Link::Link()
	: GameObject(), _imageComponent(nullptr), _inputComponent(nullptr)
{

}

Link::~Link()
{
}

Link::Link(SG::Vector3 location)
	: Link()
{
	_location = location;
}

Link::Link(SG::Vector3 location, SG::Controller* controller)
	:Link(location)
{
	_inputComponent = std::make_unique<SG::InputComponent>(controller);
}

void Link::Startup()
{
	_imageComponent = std::make_unique<SG::ImageComponent>(SG::SpriteSheetEnum::Link, SG::Point{32,32});
}

void Link::Update(const double& deltaTime)
{
	HandleInput();
	ComponentUpdate();
}

void Link::Draw(SG::SpriteBatch& spriteBatch)
{
	_imageComponent->Draw(spriteBatch);

}


void Link::ComponentUpdate()
{
	_imageComponent->Update(_location);
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