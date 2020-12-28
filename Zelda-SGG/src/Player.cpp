#include "Player.h"
#include "ImageComponent.h"
#include "Point.h"

Player::Player()
	:GameObject()
{

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
}

void Player::Draw(SG::SpriteBatch& spriteBatch)
{
	_imageComponent->Draw(spriteBatch);

}


void Player::ComponentUpdate()
{
}
