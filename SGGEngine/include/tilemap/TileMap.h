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

namespace SG
{
	/**
	 * \brief This class is used to send back the full tilemap of the level.  It uses the Tiled class to generate the json data, and this parses through it to create the size and shape of it
	 */
	class SGGENGINE_API TileMap
	{
	public:

		TileMap() = default;
		~TileMap() = default;

		/**
		 * \brief This is the main way to generate a tilemap, it is loaded from tiled and processed into a tilemap.
		 * \param mapName String of the file name that should be loaded via tiled
		 * \return The tilemap with the map data
		 */
		static TileMap* GenerateTileMap(std::string mapName);

		nlohmann::basic_json<> JsonMapData = nullptr;
		nlohmann::basic_json<> JsonSolidLayer = nullptr;

		int WidthOfMap = 0;
		int HeightOfMap = 0;

	private:
		inline static const std::string Layers = "layers";
		inline static const std::string Width = "width";
		inline static const std::string Data = "data";
		inline static const std::string Height = "height";
	};
}
