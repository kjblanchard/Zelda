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
	ITakeDamage(int maxHp, int currentHp = 0) { _maxHp = currentHp; if (currentHp != 0)_currentHp = currentHp; else _currentHp = maxHp; }
	virtual ~ITakeDamage() = default;
protected:
	virtual void TakeDamage(Damage* damage) = 0;
	int ApplyDamage(int damageAmount) { _currentHp -= damageAmount; return _currentHp; }
	int _maxHp;
	int _currentHp;

};
