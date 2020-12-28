#include "pch.h"
#include "GameObject.h"
#include "Graphics.h"
#include "Game.h"
#include "SpriteBatch.h"


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




