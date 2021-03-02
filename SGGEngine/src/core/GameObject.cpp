#include "pch.h"
#include "core/GameObject.h"
#include "data/Directions.h"


SG::GameObject::GameObject()
	: GameObjectType(GameObjectTypes::Default), _location{Vector3()}, _currentDirection(SG::Directions::Down)
{
	++GameObjectCount;
	Id = GameObjectCount;
}


SG::GameObject::GameObject(Vector3 location, GameObjectTypes gameObjectType)
	: GameObjectType(gameObjectType), _location(location), _currentDirection(SG::Directions::Down)
{
	++GameObjectCount;
	Id = GameObjectCount;
}

SG::Component* SG::GameObject::GetComponent(SGComponentTypes componentType)
{
	for (auto* component : _components)
	{
		if (component->ComponentType() == componentType)
			return component;
	}
	return nullptr;
}







