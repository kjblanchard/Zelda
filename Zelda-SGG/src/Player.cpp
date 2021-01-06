#include "Player.h"
#include "ImageComponent.h"
#include "PlayerController.h"
#include "Point.h"

Player::Player()
	: GameObject(), _imageComponent(nullptr), _inputComponent(nullptr)
{
	printf("aliv");
	auto* controller = new SG::PlayerController();
	_inputComponent = new SG::InputComponent(controller);
}

Player::~Player()
{
	printf("ded");
}

Player::Player(SG::Vector3 location)
	: GameObject(location)
{
}

void Player::Startup()
{
	_imageComponent = new SG::ImageComponent("hero.png", SG::Point{32,32});
}

void Player::Update()
{
	if(_inputComponent)
	{
		if (_inputComponent->Controller->IsButtonPressed(SG::ControllerButtons::A))
			printf("button pressed chump");
	}
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
