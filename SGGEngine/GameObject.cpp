#include "pch.h"
#include "GameObject.h"


SG::GameObject::GameObject()
	:_location{ Vector3() }
{
}


SG::GameObject::GameObject(Vector3 location)
	:_location(location)
{
}


void SG::GameObject::Draw(SpriteBatch& spriteBatch)
{
}

SG::Vector3 SG::GameObject::Location() const
{
	return _location;
}




