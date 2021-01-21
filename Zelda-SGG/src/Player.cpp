#include "Player.h"
#include "PlayerController.h"
#include <Input.h>
#include "components/ImageComponent.h"
#include "components/InputComponent.h"
#include "Spritesheet.h"
#include "data/Point.h"
#include "data/Vector3.h"


Player::Player()
	: GameObject(), _imageComponent(nullptr), _inputComponent(nullptr)
{

}

Player::~Player()
{
}

Player::Player(SG::Vector3 location)
	: Player()
{
	_location = location;
}

void Player::Startup()
{

	//TODO Remove this later, this is just for ease of use until I get levels Implemented
	auto controller = SG::Input::GetPlayerController(0);

	_imageComponent = std::make_unique<SG::ImageComponent>(SG::SpriteSheetEnum::Link, SG::Point{32,32});
	_inputComponent = std::make_unique<SG::InputComponent>(controller);
}

void Player::Update(const double& deltaTime)
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
