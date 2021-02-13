////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "World.h"
#include "ZeldaLevel.h"


enum class ZeldaLevels
{
	DebugRoom = 0
};

class ZeldaWorld : public SG::World
{
public:
	ZeldaWorld();

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw() override;

private:

	std::unique_ptr<ZeldaLevel>_zeldaLevel;

};
