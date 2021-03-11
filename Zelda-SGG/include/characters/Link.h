////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "core/GameObject.h"
#include <memory>

#include "components/AnimationComponent.h"
#include "interfaces/IGameObjectMovement.h"
#include "interfaces/IGiveDamage.h"
#include "interfaces/IObjectStateMachine.h"
#include "interfaces/ITakeDamage.h"

struct ZeldaConfigData;
enum class LinkStates;
class LinkAnimationController;
enum class LinkAnimations;

namespace SG {
	enum class Directions;
	class BoxColliderComponent;
	class Controller;
	class PlayerController;
	class ImageComponent;
	class InputComponent;
}

class Link : public SG::GameObject, protected SG::IObjectStateMachine<LinkStates>, public ITakeDamage,
             public IGiveDamage, public IGameObjectMovement
{
public:

	Link(SG::Vector3 location);
	Link(SG::Vector3 location, SG::Controller* controller);

	virtual ~Link() = default;

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;

	//TODO remove this?
private:
	void ComponentUpdate(const double& deltaTime) override;
	void GenerateStates() override;

	void TakeDamage(Damage* damage) override;


	int _speed;

	/// <summary>
	/// Components
	/// </summary>
	///
	std::unique_ptr<SG::AnimationComponent<LinkAnimationController, LinkAnimations>> _animationComponent;
	std::unique_ptr<SG::InputComponent> _inputComponent;
	std::unique_ptr<SG::BoxColliderComponent> _boxColliderComponent;




	friend class LinkSpawningState;
	friend class LinkMovingState;
	friend class LinkAttackingState;
	friend class LinkHitState;
};
