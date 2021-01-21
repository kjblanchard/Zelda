#include "DebugRoomLevel.h"
#include "Player.h"
#include "Vector3.h"
#include "GameObjectList.h"
#include "Tile.h"

void DebugRoomLevel::Startup()
{
	for (int i = 0; i < TileMap.size(); ++i)
	{
		auto yLocation = i*32;

		for (int j = 0; j < TileMap[i].size(); ++j)
		{
			auto xLocation = j*32;
			_levelGameObjectList.AddToGameObjectList(SpawnTileByType(TileMap[i][j], SG::Vector3(xLocation, yLocation)));
		}
	}

	_levelGameObjectList.AddToGameObjectList(new Player(SG::Vector3(32.0)));

}

void DebugRoomLevel::Update(const double& deltaTime)
{
	_levelGameObjectList.Update(deltaTime);
}

void DebugRoomLevel::Draw(SG::SpriteBatch& spriteBatch)
{
	_levelGameObjectList.Draw(spriteBatch);
}

void DebugRoomLevel::End()
{
	_levelGameObjectList.Reset();
}

SG::Tile* DebugRoomLevel::SpawnTileByType(int tileNum, SG::Vector3 location)
{
	auto val = static_cast<SG::TileTypes>(tileNum);
	return new SG::Tile(val, location);
}
