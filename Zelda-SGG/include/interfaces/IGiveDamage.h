////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "structs/Damage.h"

class IGiveDamage
{
public:
	IGiveDamage(Damage* baseDamage);
	virtual ~IGiveDamage() { delete _baseDamage; }
	virtual Damage* GiveDamage() { return _baseDamage; }
private:

protected:
	Damage* _baseDamage;
};
