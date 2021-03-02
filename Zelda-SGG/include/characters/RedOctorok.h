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
#include "interfaces/IObjectStateMachine.h"

enum class RedOctorokAnimations;
class RedOctorokAnimationController;
class RedOctorokStates;

namespace SG {
	class BoxColliderComponent;
}

/// <summary>
/// The first enemy that we implemented!
/// </summary>
class RedOctorok : public SG::GameObject, protected SG::IObjectStateMachine<RedOctorokStates>
{
public:
	RedOctorok(SG::Vector3 location);
	~RedOctorok() override = default;

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;
	void ComponentUpdate(const double& deltaTime) override;
	void GenerateStates() override;


private:


	/// <summary>
	/// Components
	/// </summary>
	std::unique_ptr<SG::BoxColliderComponent> _boxColliderComponent;
	std::unique_ptr<SG::AnimationComponent<RedOctorokAnimationController, RedOctorokAnimations>> _animationComponent;
};
