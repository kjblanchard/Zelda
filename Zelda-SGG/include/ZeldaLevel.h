﻿////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "Level.h"


enum class ZeldaLevels;

class ZeldaLevel : public SG::Level<ZeldaLevels>
{
public:
	ZeldaLevel() : Level() {}
	void AddAllGameLevels() override;

};
