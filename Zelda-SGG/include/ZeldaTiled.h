////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "data/Point.h"
#include "tilemap/Tile.h"
#include "tilemap/Tiled.h"
#include "tilemap/SolidTile.h"
#include "tilemap/TileMap.h"


class Link;

namespace SG {
	class GameObjectList;
}


/**
 * \brief These are the tile numbers exported from tiled, and need to match the enum for spawning tiles correctly.
 */
enum class ZeldaTileTypes
{
	Default = 5,
	Rock1 = 116,
	Rock2 = 115,
	Rock3 = 114,
	Rock4 = 117,
	Rock5 = 118,
	Ground = 2,
	Tree = 3,
};


class ZeldaTiled : SG::Tiled
{
public:

	static void CreateTileMapGameObjects(const SG::TileMap& tileMap, SG::GameObjectList& gameObjectList);
	static void CreateSolidTileMapGameObjects(const SG::TileMap& tileMap, SG::GameObjectList& gameObjectList);
	static void CreatePlayersFromJson(SG::GameObjectList& gameObjectList);

private:

	static SG::Tile<ZeldaTileTypes>* SpawnTileMapTileByZeldaTileType(int tileNum, SG::Vector3 location);
	static SG::SolidTile<ZeldaTileTypes>* SpawnTileMapSolidTileByZeldaTileType(int tileNum, SG::Vector3 location);


	/**
	 * \brief Maps the specific x and y location in the tile so that it can be found in the spritesheet
	 */
	inline static std::map<ZeldaTileTypes, SG::Point> TileTypesToSpriteLocation =
	{
		{ZeldaTileTypes::Default, SG::Point(5,0)},
		{ZeldaTileTypes::Rock1, SG::Point(3,14)},
		{ZeldaTileTypes::Rock2, SG::Point(2,14)},
		{ZeldaTileTypes::Rock3, SG::Point(1,14)},
		{ZeldaTileTypes::Rock4, SG::Point(4,14)},
		{ZeldaTileTypes::Rock5, SG::Point(5,14)},
		{ZeldaTileTypes::Ground, SG::Point(1,0)},
		{ZeldaTileTypes::Tree, SG::Point{2,0}}
	};
};
