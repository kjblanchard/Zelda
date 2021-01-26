#include "DebugRoomLevel.h"
#include "Player.h"
#include "GameObjectList.h"
#include "Input.h"
#include "Sound.h"
#include "Tile.h"
#include "Tiled.h"

void DebugRoomLevel::Startup()
{
	TileMap.reset(SG::TileMap::GenerateTileMap("overworld.json"));

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

	_levelGameObjectList.AddToGameObjectList(CreatePlayerFromJson());
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

Player* DebugRoomLevel::CreatePlayerFromJson()
{
	Player* startPlayer = nullptr;
	auto jsonFile = SG::Tiled::CurrentTiledJson;
	if (jsonFile != nullptr)
	{
		if (jsonFile.contains("layers"))
		{
			auto jsonLayers = jsonFile["layers"];
			if (jsonLayers[1].contains("objects"))
			{
				auto jsonObjects = jsonLayers[1]["objects"][0];
				auto spawnX = jsonObjects["x"];
				auto spawnY = jsonObjects["y"];
				startPlayer = new Player(SG::Vector3(spawnX, spawnY), SG::Input::GetPlayerController(0));
				return startPlayer;
			}

		}
	}
	return startPlayer;
}

SG::Tile* DebugRoomLevel::SpawnTileByType(int tileNum, SG::Vector3 location)
{
	auto val = static_cast<SG::TileTypes>(tileNum);
	return new SG::Tile(val, location);
}
