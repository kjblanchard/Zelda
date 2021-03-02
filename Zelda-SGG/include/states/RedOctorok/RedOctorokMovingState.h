////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "state/State.h"

class RedOctorok;

class RedOctorokMovingState : public SG::State
{
public:
	RedOctorokMovingState(RedOctorok* owner);
	~RedOctorokMovingState() = default;
	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch & spriteBatch) override;
	void End() override;

private:
	RedOctorok* _redOctorok;
};
