////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "core/GameObject.h"
#include <memory>

namespace SG {
	class ImageComponent;
	class BoxColliderComponent;
}

class Weapon : public SG::GameObject
{
public:
	Weapon(SG::Vector3 location, GameObject* owner, SG::GameObjectTypes gameObjectType = SG::GameObjectTypes::Default );
	~Weapon() override = default;
	GameObject* Owner;
	std::unique_ptr<SG::ImageComponent> ImageComp = nullptr;
	std::unique_ptr<SG::BoxColliderComponent> BoxColliderComp = nullptr;
};
