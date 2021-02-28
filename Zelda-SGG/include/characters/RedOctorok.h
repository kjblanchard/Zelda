////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <memory>

#include "core/GameObject.h"

namespace SG {
	class InputComponent;
	class BoxColliderComponent;
}

/// <summary>
/// The first enemy that we implemented!
/// </summary>
class RedOctorok : public SG::GameObject
{
public:
	RedOctorok(SG::Vector3 location);
	~RedOctorok() override = default;

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;


private:
	std::unique_ptr<SG::BoxColliderComponent> _boxColliderComponent;
};
