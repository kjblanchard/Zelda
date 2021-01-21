////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "GameObject.h"
#include <memory>

namespace SG {
	class ImageComponent;
	class InputComponent;
}

class Player : public SG::GameObject
{
public:
	Player();
	virtual ~Player();

	Player(SG::Vector3 location);
	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;

private:
	void ComponentUpdate() override;
	void HandleInput();
	std::unique_ptr<SG::ImageComponent> _imageComponent;
	std::unique_ptr<SG::InputComponent> _inputComponent;
};
