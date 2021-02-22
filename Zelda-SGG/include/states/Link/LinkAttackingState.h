////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once

#include "state/State.h"

class WoodSwordWeapon;
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

	WoodSwordWeapon* woodSwordDisplay;

private:
	Link* _link;
	double _timeInState = 0;
	inline static double _maxTimeInState = 500;

};
