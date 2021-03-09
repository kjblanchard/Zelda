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

	void Configuration::GenerateValuesFromJson()
	{
		BaseConfigurationSettings.ScreenWidth = ConvertToJson("ScreenWidth");
		BaseConfigurationSettings.ScreenHeight = ConvertToJson("ScreenHeight");
		BaseConfigurationSettings.FrameTime = ConvertToJson("FrameTime");
		BaseConfigurationSettings.TileWidth = ConvertToJson("TileWidth");
		BaseConfigurationSettings.TileHeight = ConvertToJson("TileHeight");
	}
}
