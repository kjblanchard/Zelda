#include "ZeldaTiled.h"
#include "TileMap.h"
#include "GameObjectList.h"
#include "Input.h"
#include "Link.h"

void ZeldaTiled::CreateTileMapGameObjects(const SG::TileMap& tileMap, SG::GameObjectList& gameObjectList)
{
	int currentX = 0;
	int currentY = 0;
	for (int i = 0; i < tileMap.JsonMapData.size(); ++i)
	{
		auto yLocation = currentY * 32;
		auto xLocation = currentX * 32;
		if (++currentX >= tileMap.WidthOfMap)
		{
			currentX = 0;
			currentY++;
		}
		gameObjectList.AddToGameObjectList(SpawnTileMapTileByZeldaTileType(tileMap.JsonMapData[i], SG::Vector3(xLocation, yLocation)));
	}
}

SG::Tile<ZeldaTileTypes>* ZeldaTiled::SpawnTileMapTileByZeldaTileType(int tileNum, SG::Vector3 location)
{
	const auto tileType = static_cast<ZeldaTileTypes>(tileNum);
	const auto point = TileTypesToSpriteLocation.at(tileType);
	return new SG::Tile<ZeldaTileTypes>(tileType, location, point);
}

Link* ZeldaTiled::CreatePlayerFromJson()
{

	Link* startPlayer = nullptr;
	auto jsonFile = _currentTiledJson;
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
				startPlayer = new Link(SG::Vector3(spawnX, spawnY), SG::Input::GetPlayerController(0));
				return startPlayer;
			}
		}
	}
	return startPlayer;
}

