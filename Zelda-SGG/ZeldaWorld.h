////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "StateMachine.h"
#include "World.h"

enum class ZeldaLevels
{
	DebugRoom = 0
};

class ZeldaWorld : public SG::World
{
public:
	SG::StateMachine<ZeldaLevels> _levelStateMachine;

	void Update(const double& deltaTime) override;
	void Startup() override;
	
	


};
