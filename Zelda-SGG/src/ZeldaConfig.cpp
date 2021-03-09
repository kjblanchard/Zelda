#include "ZeldaConfig.h"
#include "external/json.hpp"


void ZeldaConfig::PopulateZeldaConfigStats()
{
	PopulateGameConfiguration();
	 PopulateCharacterStats();
	 PopulateWeaponStats();
}

void ZeldaConfig::PopulateGameConfiguration()
{
	ZeldaStats.CollisionDebug = _currentConfigJson.at("CollisionDebug").get<bool>();
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
	ThingToPopulate.HitboxXOffset = jsonObject.at("HitboxXOffset").get<int>();
	ThingToPopulate.HitboxYOffset = jsonObject.at("HitboxYOffset").get<int>();
	ThingToPopulate.HitboxWidth = jsonObject.at("HitboxWidth").get<int>();
	ThingToPopulate.HitboxHeight = jsonObject.at("HitboxHeight").get<int>();



}

void ZeldaConfig::JsonToModel(const nlohmann::json& jsonObject, WeaponModel& ThingToPopulate)
{
	ThingToPopulate.Damage = jsonObject.at("Damage").get<int>();
	ThingToPopulate.Knockback = jsonObject.at("Knockback").get<int>();
	ThingToPopulate.Cooldown = jsonObject.at("Cooldown").get<int>();
}
