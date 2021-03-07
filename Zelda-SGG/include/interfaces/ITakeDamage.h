////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "data/Point.h"

struct Damage;

namespace SG {
	enum class Directions;
	class GameObject;
}

/// <summary>
/// This interface should be attached to anything that is going to take damage
/// </summary>
class ITakeDamage
{
public:
	ITakeDamage(int maxHp,int invincibilityTime = 1000, int currentHp = 0) : _baseInvincibilityTime(invincibilityTime) { _maxHp = currentHp; if (currentHp != 0)_currentHp = currentHp; else _currentHp = maxHp; }
	virtual ~ITakeDamage() = default;
	bool _isInvincible = false;
	virtual void TakeDamage(Damage* damage) = 0;
protected:
	int ApplyDamage(int damageAmount) { _currentHp -= damageAmount; return _currentHp; }
	void SetInvincibilityTimer()
	{
		_isInvincible = true;
		_invincibilityTimer = _baseInvincibilityTime;
	}
	void UpdateInvincibilityTime(const double& deltaTime)
	{
		if(_isInvincible)
		{
			_invincibilityTimer -= deltaTime;
			if (_invincibilityTimer <= 0)
			{
				_invincibilityTimer = 0;
				_isInvincible = false;
			}
		}

	}
	void SetKnockBackAmount(int knockBackAmount)
	{
		_knockBackAmount = knockBackAmount;
	}
	void UpdateKnockBackAmount(int howMuchHasMoved)
	{
		_knockBackAmount -= howMuchHasMoved;
	}
	int _maxHp;
	int _currentHp;
	//TODO move these out of here and not public
	double _baseInvincibilityTime = 1000;
	double _invincibilityTimer = 0.0;
	int _knockBackAmount;
	int _knockBackAmountPerFrame;
	SG::Directions _knockBackDirection;

};
