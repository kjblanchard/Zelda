////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "state/State.h"

namespace SG {
	struct Point;
	enum class Directions;
}

class Link;

class LinkMovingState : public SG::State
{
public:
	LinkMovingState(Link* link);
	~LinkMovingState() override = default;

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;
	void HandleInput() override;
	void End() override;

private:

	/// <summary>
	/// Updates The animation component with the proper direction, and also updates the potential move by links speed
	/// </summary>
	/// <param name="direction">The current direction that we will be moving to</param>
	/// <param name="outPotentialMove">The potential updated move to be calculated in this function</param>
	void HandleMovement(SG::Directions direction, SG::Point& outPotentialMove) const;
	/// <summary>
	/// Check the Icharactermovement for collisions, and then update links location with the outcome
	/// </summary>
	/// <param name="potentialMove"></param>
	void HandleSolidTileCollisions(SG::Point potentialMove) const;
	/// <summary>
	/// Checks the Icharactermovement for EnemyCollisions, and takes action if there is a collision
	/// </summary>
	void HandleEnemyCollisions() const;
	Link* _link;
};
