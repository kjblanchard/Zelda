#include "ZeldaTiled.h"
#include "GameObjectList.h"
#include "Input.h"
#include "characters/Link.h"


void ZeldaTiled::CreateTileMapGameObjects(const SG::TileMap& tileMap, SG::GameObjectList& gameObjectList)
{
	int currentX = 0;
	int currentY = 0;
	for (unsigned int i = 0; i < tileMap.JsonMapData.size(); ++i)
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

void ZeldaTiled::CreateSolidTileMapGameObjects(const SG::TileMap& tileMap, SG::GameObjectList& gameObjectList)
{
	int currentX = 0;
	int currentY = 0;
	currentX = 0;
	currentY = 0;
	for (unsigned int i = 0; i < tileMap.JsonSolidLayer.size(); ++i)
	{
		auto yLocation = currentY * 32;
		auto xLocation = currentX * 32;
		if (++currentX >= tileMap.WidthOfMap)
		{
			currentX = 0;
			currentY++;
		}
		if (tileMap.JsonSolidLayer[i] == 0)
			continue;
		gameObjectList.AddToGameObjectList(SpawnTileMapSolidTileByZeldaTileType(tileMap.JsonSolidLayer[i], SG::Vector3(xLocation, yLocation)));
	}
}


SG::Tile<ZeldaTileTypes>* ZeldaTiled::SpawnTileMapTileByZeldaTileType(int tileNum, SG::Vector3 location)
{
	const auto tileType = static_cast<ZeldaTileTypes>(tileNum);
	const auto point = TileTypesToSpriteLocation.at(tileType);
	return new SG::Tile<ZeldaTileTypes>(tileType, location, point);
}

SG::SolidTile<ZeldaTileTypes>* ZeldaTiled::SpawnTileMapSolidTileByZeldaTileType(int tileNum, SG::Vector3 location)
{
	const auto tileType = static_cast<ZeldaTileTypes>(tileNum);
	const auto point = TileTypesToSpriteLocation.at(tileType);
	return new SG::SolidTile<ZeldaTileTypes>(tileType, location, point);
}

void ZeldaTiled::CreatePlayersFromJson(SG::GameObjectList& gameObjectList)
{
	auto jsonFile = _currentTiledJson;
	if (jsonFile != nullptr)
	{
		if (jsonFile.contains("layers"))
		{
			auto jsonLayers = jsonFile["layers"];
			if (jsonLayers[2].contains("objects"))
			{
				auto jsonObjects = jsonLayers[2]["objects"][0];
				auto spawnX = jsonObjects["x"];
				auto spawnY = jsonObjects["y"];
				gameObjectList.AddToGameObjectList(new Link(SG::Vector3(spawnX, spawnY), SG::Input::GetPlayerController(0)));
			}
		}
	}
}

