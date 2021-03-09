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
#include <stdexcept>

#include "DebugHandler.h"


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
		/// <summary>
		/// Loads the json file from the filename passed in
		/// </summary>
		/// <param name="fileName">A string of the filename, usually appsettings.json</param>
		static void GenerateJsonFromConfigFile(std::string fileName);
		/// <summary>
		/// Loads in all of the values from the loaded json into member variables
		/// </summary>
		static void GenerateValuesFromJson();
		/// <summary>
		/// The actual base config that should be pulled from for the program.
		/// </summary>
		static inline Config BaseConfigurationSettings;


	protected:

		/// <summary>
		/// From the root of the currently loaded json, pull a specific section
		/// </summary>
		/// <param name="thingToConvert">String of the section that you'd like to load from</param>
		/// <returns></returns>
		static nlohmann::json ConvertToJson(const std::string& thingToConvert)
		{
			if (_currentConfigJson.contains(thingToConvert))
				return _currentConfigJson.at(thingToConvert);
			DebugHandler::PrintErrorMessage(ErrorCodes::JsonLoadError);
			throw std::runtime_error("json is invalid");
		}
		/// <summary>
		/// From a loaded json file, parse out a specific section and return it.
		/// </summary>
		/// <param name="jsonToPullFrom">The loaded json file to look through</param>
		/// <param name="thingToConvert">The section that it should grab</param>
		/// <returns>The specific section from within the json file that you want</returns>
		static nlohmann::json ConvertToJson(const nlohmann::json& jsonToPullFrom, const std::string& thingToConvert)
		{
			if (jsonToPullFrom.contains(thingToConvert))
				return jsonToPullFrom.at(thingToConvert);
			DebugHandler::PrintErrorMessage(ErrorCodes::JsonLoadError);
			throw std::runtime_error("json is invalid");
		}
		/// <summary>
		/// The loaded json file from appsettings.json
		/// </summary>
		static inline nlohmann::json _currentConfigJson;

	};
}
