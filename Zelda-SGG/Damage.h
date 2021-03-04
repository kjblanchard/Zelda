////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once

namespace SG {
	class GameObject;
}

struct Damage
{
	int DamageAmount = 0;
	int PushbackAmount = 0;
	SG::GameObject* GameObjectCausingDamage;
};
