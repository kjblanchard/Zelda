////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "LinkAnimations.h"
#include "World.h"
#include "animation/AnimationController.h"
#include "animation/Animation.h"


class LinkAnimationController : public SG::AnimationController<LinkAnimations>
{
public:
	explicit LinkAnimationController(SG::GameObject* gameObject);

	void Startup() override;
	void Draw(SG::SpriteBatch& spriteBatch) override;


};
