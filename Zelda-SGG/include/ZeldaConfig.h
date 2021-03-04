////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "core/Configuration.h"
#include "models/LinkModel.h"

struct LinkModel;

class ZeldaConfig : SG::Configuration
{

public:

	static void PopulatePlayerStats();

	static LinkModel LinkBaseStats;


	static void ZeldaFromJson(const nlohmann::json& jsonObject, LinkModel& ThingToPopulate);
};


