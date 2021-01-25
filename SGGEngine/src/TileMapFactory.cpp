#include "pch.h"
#include <string>
#include <istream>
#include <fstream>
#include "GameObject.h"
#include "TileMap.h"

#include  "TileMapFactory.h"

namespace SG
{
	//statics
	std::string TileMapFactory::readFile;
	nlohmann::json TileMapFactory::jsonFile;

	TileMap* TileMapFactory::ConvertJsonFileToTileMap(std::string mapName)
	{
		std::ifstream infile{ "assets/maps/" + mapName };
		readFile = { std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>() };
		jsonFile = nlohmann::json::parse(readFile);


		auto* tilemap = new TileMap();

		if(jsonFile.contains(Layers))
		{
			auto jsonLayers = jsonFile[Layers];
			if(jsonLayers[0].contains(Width))
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

			}
		}
		return tilemap;

	}


}
