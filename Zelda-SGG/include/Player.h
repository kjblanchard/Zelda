////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "GameObject.h"
#include "InputComponent.h"
#include "Vector3.h"

namespace SG {
	class ImageComponent;
}

class Player : public SG::GameObject
{
public:
	Player();
	~Player();

	Player(SG::Vector3 location);
	void Startup() override;
	void Update() override;
	void Draw(SG::SpriteBatch& spriteBatch) override;

private:
	void ComponentUpdate() override;
	SG::ImageComponent* _imageComponent;
	SG::InputComponent* _inputComponent;
};
