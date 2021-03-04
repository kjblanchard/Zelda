#include "ZeldaConfig.h"
#include "external/json.hpp"

//statics
LinkModel ZeldaConfig::LinkBaseStats;


void ZeldaConfig::PopulatePlayerStats()
{
	nlohmann::json charactersJson = _currentConfigJson["Characters"];
	nlohmann::json linkJson = charactersJson["Link"];
	ZeldaFromJson(linkJson, LinkBaseStats);
}

void ZeldaConfig::ZeldaFromJson(const nlohmann::json& jsonObject, LinkModel& ThingToPopulate)
{
	ThingToPopulate.MaxHp = jsonObject["MaxHp"].get<int>();
	ThingToPopulate.Defense = jsonObject.at("Defense").get<int>();
	ThingToPopulate.Speed = jsonObject.at("Speed").get<int>();
	ThingToPopulate.InvincibilityFrames = jsonObject.at("InvincibilityFrames").get<int>();
	ThingToPopulate.Name = jsonObject.at("Name").get<std::string>();

}
