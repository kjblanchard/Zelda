////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "core/GameLevel.h"
#include "data/Point.h"
/// <summary>
/// Class that should be used by characters that move around in the world.  Has speed, and ability to handle tile collisions
/// </summary>
class ICharacterMovement
{

public:

	ICharacterMovement(int speed) : _speed(speed), currentGameLevel(nullptr)
	{
	}
	int _speed;
	bool _shouldCollide = true;
	bool _shouldGetHurtByEnemies = true;
	bool _isMoving = false;

	/// <summary>
	/// Checks the current players potential rectangle against the solid objects tiles, and returns the offset we should take
	/// </summary>
	/// <param name="thisGuysColliderBox"></param>
	/// <returns>Point of the offset</returns>
	SG::Point HandleSolidTileCollision(SDL_Rect thisGuysColliderBox, SG::Point potentialMove );

	/// <summary>
	/// This is used for things to interact with the enemies colliders
	/// </summary>
	/// <param name="thisGuysColliderBox">The colliderbox to check with</param>
	/// <returns>First Gameobject that is collided with, or nullptr</returns>
	SG::GameObject* PlayerHandleEnemyCollision(SDL_Rect thisGuysColliderBox);
	SG::GameLevel* currentGameLevel;
};
