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
	class SGGENGINE_API Tiled
	{
	public:

		static std::string CurrentTiledString;
		static nlohmann::json CurrentTiledJson;

		static const nlohmann::json& GenerateJsonFromTileMapFile(std::string fileName);
	};
}
