#include "pch.h"
#include <fstream>
#include  "core/Configuration.h"

namespace SG
{

	void Configuration::GenerateJsonFromConfigFile(std::string fileName)
	{
		std::ifstream infile{ "assets/configuration/" + fileName };
		std::string currentConfigString = { std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>() };
		_currentConfigJson = nlohmann::json::parse(currentConfigString);
	}

	bool Configuration::GenerateValuesFromJson()
	{
		if (!_currentConfigJson.contains(_screenWidth))
			return false;
		BaseConfigurationSettings.ScreenWidth = _currentConfigJson.at(_screenWidth);

		if (!_currentConfigJson.contains(_screenHeight))
			return false;
		BaseConfigurationSettings.ScreenHeight = _currentConfigJson.at(_screenHeight);

		if (!_currentConfigJson.contains(_frameTime))
			return false;
		BaseConfigurationSettings.FrameTime = _currentConfigJson.at(_frameTime);

		if (!_currentConfigJson.contains(_tileWidth))
			return false;
		BaseConfigurationSettings.TileWidth = _currentConfigJson.at(_tileWidth);

		if (!_currentConfigJson.contains(_tileHeight))
			return false;
		BaseConfigurationSettings.TileHeight = _currentConfigJson.at(_tileHeight);
		return true;

	}
}
