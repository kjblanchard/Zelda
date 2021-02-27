#include "pch.h"
#include "GameObject.h"
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






