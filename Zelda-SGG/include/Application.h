////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <memory>

namespace SG {
	class Game;
}

class Application
{
public:
	//TODO Make this into a better worded / thing
	void InitializeGame();

private:
	std::unique_ptr<SG::Game> _game;
};
