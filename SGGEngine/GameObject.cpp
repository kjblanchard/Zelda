#include "pch.h"
#include "GameObject.h"
#include "Graphics.h"
#include "Game.h"


SG::GameObject::GameObject()
	:_location{ Vector3() }
{

}


SG::GameObject::GameObject(Vector3 location)
	:_location(location)
{
}

SG::GameObject::~GameObject() = default;

SG::Vector3 SG::GameObject::Location() const
{
	return _location;
}

void SG::GameObject::CreateImageAndShow()
{
	auto temp = Game::GetGraphics();
	auto pic =temp->LoadTexture("Hero.png");
	temp->ThingToDraw = pic;
	temp->Draw();

}


