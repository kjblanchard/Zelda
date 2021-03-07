////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "core/World.h"
#include "animation/AnimationController.h"
#include "animation/Animation.h"
#include "animation/LinkAnimations/LinkAnimations.h"


class Link;

class LinkAnimationController : public SG::AnimationController<LinkAnimations>
{
public:
	explicit LinkAnimationController(SG::GameObject* gameObject);

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;

	Link* _link;

	//TODO remove this and the red octos and put it somewhere that makes sense and is organized and reusable
	int CalculateCurrentFrameInInvincibility()
	{
		if (currentInvincibilityFrame < maxInvFrame / 2)
			return 1;
		else
			return 2;
	}
	const int invFrameOffset = 4 * 32;
	int currentInvincibilityFrame = 0;
	const int maxInvFrame = 8;


};
