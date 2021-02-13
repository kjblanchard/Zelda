#include "pch.h"
#include "tilemap/TileMap.h"
#include "tilemap/Tiled.h"

namespace SG
{

	TileMap* TileMap::GenerateTileMap(std::string mapName)
	{
		auto jsonFile = Tiled::GenerateJsonFromTileMapFile(mapName);

		auto* tilemap = new TileMap();

		if (jsonFile.contains(Layers))
		{
			auto jsonLayers = jsonFile[Layers];
			if (jsonLayers[0].contains(Width))
			{
				tilemap->WidthOfMap = jsonFile[Layers][0][Width];
			}
			if (jsonFile[Layers][0].contains(Height))
			{
				tilemap->HeightOfMap = jsonLayers[0][Height];
			}
			if (jsonLayers[0].contains(Data))
			{
				tilemap->JsonMapData = jsonLayers[0][Data];
				tilemap->JsonSolidLayer = jsonLayers[1][Data];

			}
		}
		return tilemap;
	}
}
