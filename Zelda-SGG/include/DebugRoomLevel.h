////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "State.h"

class DebugRoomLevel : public SG::State
{
public:
	~DebugRoomLevel() = default;
	void Startup() override;
	void Update(const double& deltaTime) override;
	void End() override;
};
