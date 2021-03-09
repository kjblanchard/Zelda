#include "ZeldaConfig.h"
#include "external/json.hpp"


void ZeldaConfig::PopulatePlayerStats()
{
	nlohmann::json charactersJson = _currentConfigJson.at("Characters");
	nlohmann::json weaponsJson = _currentConfigJson.at("Weapons");

	nlohmann::json linkJson = charactersJson["Link"];
	nlohmann::json redOctoJson = charactersJson["RedOctorok"];

	nlohmann::json WoodSwordJson = weaponsJson["WoodSword"];
	nlohmann::json WoodBallJson = weaponsJson["WoodBall"];

	CharacterFromJson(linkJson, LinkBaseStats);
	CharacterFromJson(redOctoJson, RedOctoBaseStats);

	WeaponFromJson(WoodSwordJson, WoodSwordBaseStats);
	WeaponFromJson(WoodBallJson, WoodBallBaseStats);

}

void ZeldaConfig::CharacterFromJson(const nlohmann::json& jsonObject, CharacterModel& ThingToPopulate)
{
	ThingToPopulate.MaxHp = jsonObject["MaxHp"].get<int>();
	ThingToPopulate.Defense = jsonObject.at("Defense").get<int>();
	ThingToPopulate.Speed = jsonObject.at("Speed").get<int>();
	ThingToPopulate.InvincibilityTime = jsonObject.at("InvincibilityTime").get<int>();
	ThingToPopulate.Name = jsonObject.at("Name").get<std::string>();

}

void ZeldaConfig::WeaponFromJson(const nlohmann::json& jsonObject, WeaponModel& ThingToPopulate)
{
	ThingToPopulate.Damage = jsonObject.at("Damage").get<int>();
	ThingToPopulate.Knockback = jsonObject.at("Knockback").get<int>();
	ThingToPopulate.Cooldown = jsonObject.at("Cooldown").get<int>();
}
