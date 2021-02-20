////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "state/State.h"

class Link;

class LinkMovingState : public SG::State
{
public:
	LinkMovingState(Link* link);
	~LinkMovingState() override = default;

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;
	void HandleInput() override;
	void End() override;

	Link* _link;
};
