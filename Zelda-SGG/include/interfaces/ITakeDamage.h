////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once

struct Damage;

namespace SG {
	class GameObject;
}

/// <summary>
/// This interface should be attached to anything that is going to take damage
/// </summary>
class ITakeDamage
{
public:
	virtual ~ITakeDamage() = default;
private:
	virtual void TakeDamage(Damage* damage) = 0;

};
