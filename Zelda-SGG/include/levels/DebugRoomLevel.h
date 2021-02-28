////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "core/GameLevel.h"
#include "tilemap/TileMap.h"



class Link;

namespace SG {
	enum class TileTypes;
}

class DebugRoomLevel : public SG::GameLevel
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
