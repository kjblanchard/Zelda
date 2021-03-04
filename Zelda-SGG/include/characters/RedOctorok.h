////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include <memory>

#include "components/AnimationComponent.h"
#include "core/GameObject.h"
#include "interfaces/IGiveDamage.h"
#include "interfaces/IObjectStateMachine.h"
#include "interfaces/ITakeDamage.h"

enum class RedOctorokStates;
class RedOctorokMovingState;
class RedOctorokSpawningState;
enum class RedOctorokAnimations;
class RedOctorokAnimationController;

namespace SG {
	class BoxColliderComponent;
}

/// <summary>
/// The first enemy in the game, the little red circle dude that shoots the wood balls all over
/// </summary>
class RedOctorok : public SG::GameObject, public IGiveDamage, public ITakeDamage, protected SG::IObjectStateMachine<RedOctorokStates>
{
public:
	RedOctorok(SG::Vector3 location);
	~RedOctorok() override = default;

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;
	void ComponentUpdate(const double& deltaTime) override;
	void GenerateStates() override;

	Damage* GiveDamage() override;
	void TakeDamage(Damage* damage) override;

private:


	/// <summary>
	/// Components
	/// </summary>
	std::unique_ptr<SG::BoxColliderComponent> _boxColliderComponent;
	std::unique_ptr<SG::AnimationComponent<RedOctorokAnimationController, RedOctorokAnimations>> _animationComponent;

	friend RedOctorokSpawningState;
	friend RedOctorokMovingState;
};
