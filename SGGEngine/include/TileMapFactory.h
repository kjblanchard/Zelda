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

#include "external/json.hpp"


class Player;

namespace SG
{
	class TileMap;

	class SGGENGINE_API TileMapFactory
	{
public:
		static std::string readFile;
		static nlohmann::json jsonFile;

		static TileMap* ConvertJsonFileToTileMap(std::string mapName);

		static nlohmann::json& ReturnLevelJson()
		{
			return jsonFile;
		}

	private:

		inline static const std::string Layers = "layers";
		inline static const std::string Width = "width";
		inline static const std::string Data = "data";
		inline static const std::string Height = "height";


	};

}
