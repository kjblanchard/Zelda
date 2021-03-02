////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "RedOctorokAnimations.h"
#include "animation/AnimationController.h"

class RedOctorokAnimationController : public SG::AnimationController<RedOctorokAnimations>
{
public:
	RedOctorokAnimationController(SG::GameObject* owner);

	void Startup() override;
	void Draw(SG::SpriteBatch& spriteBatch) override;
};
