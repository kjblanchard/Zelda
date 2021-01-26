#include "pch.h"

#include  "Tiled.h"
#include <fstream>

namespace SG
{
	//statics
	std::string Tiled::CurrentTiledString;
	nlohmann::json Tiled::CurrentTiledJson;

	const nlohmann::json& Tiled::GenerateJsonFromTileMapFile(std::string fileName)
	{

		std::ifstream infile{ "assets/maps/" + fileName };
		CurrentTiledString = { std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>() };
		CurrentTiledJson = nlohmann::json::parse(CurrentTiledString);

		return CurrentTiledJson;
	}
}
