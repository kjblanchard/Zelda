#include "pch.h"
#include <fstream>
#include  "core/Configuration.h"

namespace SG
{
	//statics
	std::string Configuration::_currentConfigString;
	nlohmann::json Configuration::_currentConfigJson;

	const void Configuration::GenerateJsonFromConfigFile(std::string fileName)
	{
		std::ifstream infile{ "assets/configuration/" + fileName };
		_currentConfigString = { std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>() };
		_currentConfigJson = nlohmann::json::parse(_currentConfigString);
	}

	bool Configuration::GenerateValuesFromJson()
	{

		if (!_currentConfigJson.contains(_ScreenWidth))
			return false;
		ScreenWidth = _currentConfigJson[_ScreenWidth];

		if (!_currentConfigJson.contains(_ScreenHeight))
			return false;
		ScreenHeight = _currentConfigJson[_ScreenHeight];

		if (!_currentConfigJson.contains(_FrameTime))
			return false;
		FrameTime = _currentConfigJson[_FrameTime];

		if (!_currentConfigJson.contains(_TileWidth))
			return false;
		TileWidth = _currentConfigJson[_TileWidth];

		if (!_currentConfigJson.contains(_TileHeight))
			return false;
		TileHeight = _currentConfigJson[_TileHeight];
		return true;

	}
}
