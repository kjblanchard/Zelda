//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <memory>
class Player;

namespace SG {
	class SpriteBatch;
	class Game;
}

class Application
{
public:

	void InitializeGame();

private:
	std::unique_ptr<SG::Game> _game;

};
