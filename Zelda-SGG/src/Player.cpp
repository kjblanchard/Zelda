#include "Player.h"
#include "ImageComponent.h"
#include "PlayerController.h"
#include "Point.h"

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
	_imageComponent = new SG::ImageComponent("hero.png", SG::Point{32,32});
	auto* controller = new SG::PlayerController();
	_inputComponent = new SG::InputComponent(controller);
}

void Player::Update()
{
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
