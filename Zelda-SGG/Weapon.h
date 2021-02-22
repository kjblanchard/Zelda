////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "GameObject.h"

namespace SG {
	class ImageComponent;
	class BoxColliderComponent;
}

class Weapon : public SG::GameObject
{
public:
	Weapon(SG::Vector3 location, GameObject* owner, SG::GameObjectTypes gameObjectType = SG::GameObjectTypes::Default );
	~Weapon() = default;
	GameObject* Owner;
	SG::ImageComponent* ImageComp;
	SG::BoxColliderComponent* BoxColliderComp;
};
