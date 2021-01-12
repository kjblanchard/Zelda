//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <memory>

class ZeldaWorld;
class Player;

namespace SG {
	class SpriteBatch;
	class World;
}

class Application
{
public:

	void InitializeGame();

private:
	std::unique_ptr<ZeldaWorld> _game;

};
