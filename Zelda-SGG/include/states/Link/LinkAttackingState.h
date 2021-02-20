////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <SDL_stdinc.h>
#include <SDL_timer.h>


#include "state/State.h"

class Link;

class LinkAttackingState : public SG::State
{
public:
	LinkAttackingState(Link* link) : _link(link) {  }
	~LinkAttackingState() = default;

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;
	void End() override;

private:
	Link* _link;

	static Uint32 Callback(Uint32 interval, void* param);
};
