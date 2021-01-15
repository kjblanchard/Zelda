////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "GameObjectList.h"
#include "Point.h"
#include "State.h"

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

private:

	std::vector<std::vector<int>> TileMap
	{
		{1,1,1,1,1,1,1,6,6,1,1,1,1,1,1,1},
		{1,1,1,1,0,1,4,6,6,1,1,1,1,1,1,1},
		{1,1,1,4,6,6,6,6,6,1,1,1,1,1,1,1},
		{1,1,4,6,6,6,6,6,6,1,1,1,1,1,1,1},
		{1,4,6,6,6,6,6,6,6,5,1,1,1,1,1,1},
		{6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6},
		{2,3,6,6,6,6,6,6,6,6,6,6,6,6,2,2},
		{1,1,6,6,6,6,6,6,6,6,6,6,6,6,1,1},
		{1,1,6,6,6,6,6,6,6,6,6,6,6,6,1,1},
		{1,1,2,2,2,2,2,2,2,2,2,2,2,2,1,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};

	SG::Tile* SpawnTileByType(int tileNum, SG::Vector3 location);
	SG::GameObjectList _levelGameObjectList;

};
