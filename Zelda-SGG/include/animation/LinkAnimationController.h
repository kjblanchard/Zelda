////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "animation/AnimationController.h"

enum class LinkAnimations
{
	Default,
	Idle,
	WalkUp,
	WalkRight,
	WalkDown,
	WalkLeft
};


class LinkAnimationController : public SG::AnimationController<LinkAnimations>
{
	LinkAnimationController(SG::GameObject* gameObject) : AnimationController(gameObject) {}

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;
	void ChangeAnimation(LinkAnimations animationEnum) override;


};
