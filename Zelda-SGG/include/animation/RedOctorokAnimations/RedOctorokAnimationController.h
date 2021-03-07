////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "animation/AnimationController.h"

class RedOctorok;
enum class RedOctorokAnimations;

class RedOctorokAnimationController : public SG::AnimationController<RedOctorokAnimations>
{
public:
	RedOctorokAnimationController(SG::GameObject* owner);
	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;


private:

	RedOctorok* _redOcto;
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
