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
	class Controller;
	class PlayerController;
	class ImageComponent;
	class InputComponent;
}

class Link : public SG::GameObject
{
public:
	Link();
	virtual ~Link();

	Link(SG::Vector3 location);
	Link(SG::Vector3 location, SG::Controller* controller);
	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;

private:
	void ComponentUpdate() override;
	void HandleInput();
	std::unique_ptr<SG::ImageComponent> _imageComponent;
	std::unique_ptr<SG::InputComponent> _inputComponent;
};
