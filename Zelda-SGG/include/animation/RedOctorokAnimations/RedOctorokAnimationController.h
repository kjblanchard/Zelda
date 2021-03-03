////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "animation/AnimationController.h"

enum class RedOctorokAnimations;

class RedOctorokAnimationController : public SG::AnimationController<RedOctorokAnimations>
{
public:
	RedOctorokAnimationController(SG::GameObject* owner);
	void Startup() override;
	void Draw(SG::SpriteBatch& spriteBatch) override;
};
