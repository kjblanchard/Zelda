////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "GameObject.h"
#include <memory>
#include "components/AnimationComponent.h"
#include "state/StateMachine.h"

enum class LinkStates;
class LinkAnimationController;
enum class LinkAnimations;

namespace SG {
	class BoxColliderComponent;
	class Controller;
	class PlayerController;
	class ImageComponent;
	class InputComponent;
}

class Link : public SG::GameObject
{
public:

	Link(SG::Vector3 location);
	Link(SG::Vector3 location, SG::Controller* controller);
	virtual ~Link();

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;

private:
	void ComponentUpdate(const double& deltaTime) override;
	void HandleInput();

	void GenerateStates();
	SG::StateMachine<LinkStates>* _linkStateMachine = new SG::StateMachine<LinkStates>;

		/// <summary>
	/// Components
	/// </summary>
	///
	std::unique_ptr<SG::AnimationComponent<LinkAnimationController, LinkAnimations>> _animationComponent;
	std::unique_ptr<SG::InputComponent> _inputComponent;
	std::unique_ptr<SG::BoxColliderComponent> _boxColliderComponent;
};
