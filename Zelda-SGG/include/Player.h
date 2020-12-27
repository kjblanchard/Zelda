////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "GameObject.h"
#include "Vector3.h"

class Player : public SG::GameObject
{
public:
	Player();
	Player(SG::Vector3 location);
	void Startup() override;
	void Update() override;
};
