////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "GameObjectList.h"
#include "State.h"
#include "Tile.h"
#include "TileMap.h"
#include "interfaces/ILevel.h"

class Link;

namespace SG {
	enum class TileTypes;
}

class DebugRoomLevel : public SG::State, public SG::ILevel
{
public:
	~DebugRoomLevel() = default;
	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;
	void End() override;

private:
	std::unique_ptr<SG::TileMap> TileMap;
};
