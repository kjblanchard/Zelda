#include "ZeldaConfig.h"
#include "external/json.hpp"


void ZeldaConfig::PopulateZeldaConfigStats()
{
	 PopulateCharacterStats();
	 PopulateWeaponStats();
}

void ZeldaConfig::PopulateCharacterStats()
{
	const nlohmann::json charactersJson = ConvertToJson("Characters");
	JsonToModel(ConvertToJson(charactersJson, "Link"), ZeldaStats.LinkBaseStats);
	JsonToModel(ConvertToJson(charactersJson, "RedOctorok"), ZeldaStats.RedOctoBaseStats);
}

void ZeldaConfig::PopulateWeaponStats()
{
	const nlohmann::json weaponsJson = ConvertToJson("Weapons");
	JsonToModel(ConvertToJson(weaponsJson, "WoodSword"), ZeldaStats.WoodSwordBaseStats);
	JsonToModel(ConvertToJson(weaponsJson, "WoodBall"), ZeldaStats.WoodBallBaseStats);
}


void  ZeldaConfig::JsonToModel(const  nlohmann::json& jsonObject, CharacterModel& ThingToPopulate)
{
	ThingToPopulate.MaxHp = jsonObject["MaxHp"].get<int>();
	ThingToPopulate.Defense = jsonObject.at("Defense").get<int>();
	ThingToPopulate.Speed = jsonObject.at("Speed").get<int>();
	ThingToPopulate.InvincibilityTime = jsonObject.at("InvincibilityTime").get<int>();
	ThingToPopulate.Name = jsonObject.at("Name").get<std::string>();
}

void ZeldaConfig::JsonToModel(const nlohmann::json& jsonObject, WeaponModel& ThingToPopulate)
{
	ThingToPopulate.Damage = jsonObject.at("Damage").get<int>();
	ThingToPopulate.Knockback = jsonObject.at("Knockback").get<int>();
	ThingToPopulate.Cooldown = jsonObject.at("Cooldown").get<int>();
}
