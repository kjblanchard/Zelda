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
		int WidthOfMap = 0;
		int HeightOfMap = 0;
	};
}
