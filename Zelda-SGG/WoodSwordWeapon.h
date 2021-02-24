////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "Weapon.h"
#include "data/Directions.h"
#include "data/Point.h"

class WoodSwordWeapon : public Weapon
{
public:

	WoodSwordWeapon(SG::Vector3 location, GameObject* owner, SG::GameObjectTypes gameObjectType = SG::GameObjectTypes::Default );
	~WoodSwordWeapon() = default;
	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;
	void Reset() override;

	std::pair<SG::Point,SG::Point> ReturnSwordOffsets(SG::Directions direction)
	{
		return swordSpriteSheetLocationsAndOffset[(int)(direction)];
	}

	std::pair<SG::Point, SG::Point> ReturnSwordColliderOffsets(SG::Directions direction)
	{
		return boxCollidersizeAndOffset[(int)direction];
	}
	static inline std::vector<std::pair<SG::Point, SG::Point>> swordSpriteSheetLocationsAndOffset =
	{
		 {SG::Point(0,0), SG::Point(0,16)},
		{SG::Point(0,96), SG::Point(-16,0)},
		{SG::Point(0,32), SG::Point(0,-16)},
		{SG::Point(0,64), SG::Point(16,0)},
	};

	static inline std::vector<std::pair<SG::Point, SG::Point>> boxCollidersizeAndOffset =
	{
		{std::pair<SG::Point,SG::Point>(SG::Point(0,10),SG::Point(10,24))},
		{std::pair<SG::Point,SG::Point>(SG::Point(-10,0),SG::Point(24,10))},
		{std::pair<SG::Point,SG::Point>(SG::Point(0,-10),SG::Point(10,24))},
		{std::pair<SG::Point,SG::Point>(SG::Point(10,0),SG::Point(24,10))},
	};

};
