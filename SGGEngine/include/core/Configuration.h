////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#ifdef SGGENGINE_EXPORTS
#define SGGENGINE_API __declspec(dllexport)
#else
#define SGGENGINE_API __declspec(dllimport)
#endif
#include <external/json.hpp>


namespace SG
{
	/// <summary>
	/// This is all of the information that should be stored inside of the base configuration file for Every game developed with this engine
	/// </summary>
	struct Config
	{
		int ScreenWidth;
		int ScreenHeight;
		double FrameTime;
		int TileWidth;
		int TileHeight;
	};

	/// <summary>
	/// Mostly a static class that can be referenced throughout the program to get the set game variables.  Is initialized in the world class
	/// </summary>
	class SGGENGINE_API Configuration
	{
	public:
		static void GenerateJsonFromConfigFile(std::string fileName);
		static bool GenerateValuesFromJson();
		static inline Config BaseConfigurationSettings;


	protected:
		static inline nlohmann::json _currentConfigJson;
		inline static const std::string _screenWidth = "ScreenWidth";
		inline static const std::string _screenHeight = "ScreenHeight";
		inline static const std::string _frameTime = "FrameTime";
		inline static const std::string _tileWidth = "TileWidth";
		inline static const std::string _tileHeight = "TileHeight";

	};
}
