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
	class SGGENGINE_API Configuration
	{
	public:
		static nlohmann::json CurrentConfigJson()
		{
			return _currentConfigJson;
		}

		static const void GenerateJsonFromConfigFile(std::string fileName);

		static bool GenerateValuesFromJson();


		static nlohmann::json _currentConfigJson;
		static std::string _currentConfigString;


		static inline int ScreenWidth = 0;
		static inline int ScreenHeight = 0;
		static inline double FrameTime = 0.0;
		static inline int TileWidth = 0;
		static inline int TileHeight = 0;


	private:
		inline static const std::string _ScreenWidth = "ScreenWidth";
		inline static const std::string _ScreenHeight = "ScreenHeight";
		inline static const std::string _FrameTime = "FrameTime";
		inline static const std::string _TileWidth = "TileWidth";
		inline static const std::string _TileHeight = "TileHeight";

	};
}
