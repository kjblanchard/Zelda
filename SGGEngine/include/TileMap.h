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
	class SGGENGINE_API TileMap
	{
	public:

		TileMap() = default;
		~TileMap();
		nlohmann::basic_json<> JsonMapData = nullptr;
		nlohmann::basic_json<> JsonSolidLayer = nullptr;
		int WidthOfMap = 0;
		int HeightOfMap = 0;
		static TileMap* GenerateTileMap(std::string mapName);

	private:
		inline static const std::string Layers = "layers";
		inline static const std::string Width = "width";
		inline static const std::string Data = "data";
		inline static const std::string Height = "height";
	};
}
