#include "Player.h"
#include "ImageComponent.h"
#include "PlayerController.h"
#include "Point.h"
#include <Input.h>

Player::Player()
	: GameObject(), _imageComponent(nullptr), _inputComponent(nullptr)
{

}

Player::~Player()
= default;

Player::Player(SG::Vector3 location)
	: Player()
{
	_location = location;
}

void Player::Startup()
{

	//TODO Remove this later, this is just for ease of use until I get levels Implemented
	auto controller = SG::Input::GetPlayerController(0);

	_imageComponent = std::make_unique<SG::ImageComponent>("hero.png", SG::Point{32,32});
	_inputComponent = std::make_unique<SG::InputComponent>(controller);
}

void Player::Update()
{
	HandleInput();
	ComponentUpdate();
}

void Player::Draw(SG::SpriteBatch& spriteBatch)
{
	_imageComponent->Draw(spriteBatch);

}


void Player::ComponentUpdate()
{
	_imageComponent->Update(_location);
}

void Player::HandleInput()
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
