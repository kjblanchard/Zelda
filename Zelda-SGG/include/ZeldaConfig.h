////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "core/Configuration.h"
#include "models/CharacterModel.h"
#include "models/WeaponModel.h"


class ZeldaConfig : SG::Configuration
{

public:

	static void PopulatePlayerStats();

	static inline CharacterModel LinkBaseStats{};
	static inline CharacterModel RedOctoBaseStats{};

	static inline WeaponModel WoodSwordBaseStats{};
	static inline WeaponModel WoodBallBaseStats{};



	static void CharacterFromJson(const nlohmann::json& jsonObject, CharacterModel& ThingToPopulate);
	static void WeaponFromJson(const nlohmann::json& jsonObject, WeaponModel& ThingToPopulate);
};


