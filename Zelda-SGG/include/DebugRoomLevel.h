////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "GameObjectList.h"
#include "State.h"
#include "TileMap.h"

class Player;

namespace SG {
	class Tile;
	enum class TileTypes;
}

class DebugRoomLevel : public SG::State
{
public:
	~DebugRoomLevel() = default;
	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;
	void End() override;

	Player* CreatePlayerFromJson();

private:

	SG::Tile* SpawnTileByType(int tileNum, SG::Vector3 location);
	std::unique_ptr<SG::TileMap> TileMap;
	SG::GameObjectList _levelGameObjectList;

};
