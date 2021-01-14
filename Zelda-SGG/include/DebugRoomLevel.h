﻿////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "GameObjectList.h"
#include "State.h"

namespace SG {
}

class DebugRoomLevel : public SG::State
{
public:
	~DebugRoomLevel() = default;
	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;
	void End() override;

private:

	SG::GameObjectList _levelGameObjectList;

};