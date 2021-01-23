#include "DebugRoomLevel.h"
#include "Player.h"
#include "GameObjectList.h"
#include "Sound.h"
#include "Tile.h"
#include "TileMapFactory.h"

void DebugRoomLevel::Startup()
{
	TileMap.reset(SG::TileMapFactory::ConvertJsonFileToTileMap("overworld.json"));

	int currentX = 0;
	int currentY = 0;
	for (int i = 0; i < TileMap->JsonMapData.size(); ++i)
	{
		auto yLocation = currentY * 32;
		auto xLocation = currentX * 32;
		if(++currentX >= TileMap->WidthOfMap)
		{
			currentX = 0;
			currentY++;
		}
			_levelGameObjectList.AddToGameObjectList(SpawnTileByType(TileMap->JsonMapData[i], SG::Vector3(xLocation, yLocation)));
	}

	_levelGameObjectList.AddToGameObjectList(new Player(SG::Vector3(32.0)));

	SG::Sound::PlayMusic(SG::MusicToPlay::Overworld);

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
