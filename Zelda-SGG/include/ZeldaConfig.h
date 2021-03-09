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

struct ZeldaConfigData
{
	bool CollisionDebug;

	CharacterModel LinkBaseStats;
	CharacterModel RedOctoBaseStats;

	WeaponModel WoodSwordBaseStats;
	WeaponModel WoodBallBaseStats;
};

/// <summary>
/// The Zelda configuration loader and DB.  Inherits from SG configuration, so it also has the base game configuration as well.
/// </summary>
class ZeldaConfig : SG::Configuration
{

public:
	/// <summary>
	/// Loads the characters and weapons from the json file loaded in the actual Configuration
	/// </summary>
	static void PopulateZeldaConfigStats();
	/// <summary>
	/// The actual stats that the game should be referencing / modifying after it's loaded
	/// </summary>
	static inline ZeldaConfigData ZeldaStats;

private:

	/// <summary>
	/// Loads in the game configuration stats to the in game variables
	/// ex: debug boxes
	/// </summary>
	static void PopulateGameConfiguration();

	/// <summary>
	/// Loads the character stats from the json file
	/// </summary>
	static void PopulateCharacterStats();
	/// <summary>
	/// Loads the weapon stats from the json file
	/// </summary>
	static void PopulateWeaponStats();
	/// <summary>
	/// Loads a character configuration from json
	/// </summary>
	/// <param name="jsonObject">The json reference of the section that should be parsed</param>
	/// <param name="ThingToPopulate">A reference to where the model should be put</param>
	static void JsonToModel(const nlohmann::json& jsonObject, CharacterModel& ThingToPopulate);
	/// <summary>
	/// Loads a Weapon configuration from json
	/// </summary>
	/// <param name="jsonObject">The json reference of the section that should be parsed</param>
	/// <param name="ThingToPopulate">A reference to where the model should be put</param>
	static void JsonToModel(const nlohmann::json& jsonObject, WeaponModel& ThingToPopulate);


};


