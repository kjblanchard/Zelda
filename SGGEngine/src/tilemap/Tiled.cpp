#include "pch.h"
#include "tilemap/Tiled.h"

#include <fstream>

namespace SG
{
	//statics
	std::string Tiled::_currentTiledString;
	nlohmann::json Tiled::_currentTiledJson;

	const nlohmann::json& Tiled::GenerateJsonFromTileMapFile(std::string fileName)
	{
		std::ifstream infile{ "assets/maps/" + fileName };
		_currentTiledString = { std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>() };
		_currentTiledJson = nlohmann::json::parse(_currentTiledString);
		return _currentTiledJson;
	}
}
