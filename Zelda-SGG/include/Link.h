﻿////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "GameObject.h"
#include <memory>

namespace SG {
	class AnimationComponent;
	class Controller;
	class PlayerController;
	class ImageComponent;
	class InputComponent;
}

class Link : public SG::GameObject
{
public:

	Link(SG::Vector3 location);
	Link(SG::Vector3 location, SG::Controller* controller);
	virtual ~Link();

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;

private:
	void ComponentUpdate() override;
	void HandleInput();

/// <summary>
/// Components
/// </summary>
private:
	//std::unique_ptr<SG::ImageComponent> _imageComponent;

	SG::AnimationComponent* _animationComponent;
	std::unique_ptr<SG::InputComponent> _inputComponent;
};
