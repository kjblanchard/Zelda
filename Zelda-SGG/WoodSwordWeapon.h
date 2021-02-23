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

	SG::Point ReturnSwordOffsets(SG::Directions direction)
	{
		switch (direction)
		{
		case SG::Directions::Up:
			return swordDrawOffsets[0];
			break;
		case SG::Directions::Down:
			return swordDrawOffsets[1];
			break;
		case SG::Directions::Left:
			return swordDrawOffsets[2];
			break;
		case SG::Directions::Right:
			return swordDrawOffsets[3];
		}
	}
	static inline std::vector<SG::Point> swordSpriteSheetLocations =
	{
		{0,0},
		{0,32},
		{0,64},
		{0,96}
	};

	static inline std::vector<SG::Point> swordDrawOffsets =
	{
		{0,16},
		{0,-16},
		{16,0},
		{-16,0}
	};

};
