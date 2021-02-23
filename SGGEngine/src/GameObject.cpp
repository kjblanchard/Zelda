#include "pch.h"
#include "GameObject.h"

#include "data/Directions.h"


SG::GameObject::GameObject()
	:_location{ Vector3() }, _currentDirection(SG::Directions::Down)
{
	++GameObjectCount;
	Id = GameObjectCount;
}


SG::GameObject::GameObject(Vector3 location, GameObjectTypes gameObjectType)
	:GameObjectType(gameObjectType), _location(location)
{
	++GameObjectCount;
	Id = GameObjectCount;
}

void SG::GameObject::Startup()
{
}

void SG::GameObject::Update(const double& deltaTime)
{
}



void SG::GameObject::AddComponent(Component* component)
{
	_components.push_back(component);
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

void SG::GameObject::ComponentUpdate(const double& deltaTime)
{
}




