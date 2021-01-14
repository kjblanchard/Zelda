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

void SG::GameObject::Startup()
{
}

void SG::GameObject::Update(const double& deltaTime)
{
}

void SG::GameObject::ComponentUpdate()
{
}


void SG::GameObject::Draw(SpriteBatch& spriteBatch)
{
}

void SG::GameObject::Reset()
{
}

bool SG::GameObject::ShouldUpdate() const
{
	return _shouldUpdate;
}

SG::Vector3 SG::GameObject::Location() const
{
	return _location;
}




