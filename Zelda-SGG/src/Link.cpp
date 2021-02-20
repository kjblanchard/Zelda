﻿#include "Link.h"
#include "components/InputComponent.h"
#include "components/BoxColliderComponent.h"
#include "animation/LinkAnimationController.h"
#include "states/Link/LinkStates.h"
#include "states/Link/LinkSpawningState.h"
#include "states/Link/LinkMovingState.h"


Link::Link(SG::Vector3 location)
	: GameObject(location), _animationComponent(nullptr),_inputComponent(nullptr)
{
}

Link::Link(SG::Vector3 location, SG::Controller* controller)
	: Link(location)
{
	_inputComponent = std::make_unique<SG::InputComponent>(controller, this);
	_animationComponent = std::make_unique<SG::AnimationComponent<LinkAnimationController, LinkAnimations>>(this, new LinkAnimationController(this));
	auto boxColliderBox = SDL_Rect{ 0,0,24,24 };
	_boxColliderComponent = std::make_unique<SG::BoxColliderComponent>(this,boxColliderBox);
}

Link::~Link()
{
}


void Link::Startup()
{
	GenerateStates();
	_linkStateMachine->ChangeState(LinkStates::Spawning);
}

void Link::Update(const double& deltaTime)
{
	_linkStateMachine->Update(deltaTime);
	ComponentUpdate(deltaTime);
}

void Link::Draw(SG::SpriteBatch& spriteBatch)
{
	_animationComponent->Draw(spriteBatch);
	_boxColliderComponent->Draw(spriteBatch);

}

void Link::ComponentUpdate(const double& deltaTime)
{
	_animationComponent->Update(deltaTime);
	_boxColliderComponent->Update(deltaTime);
}


void Link::GenerateStates()
{
	_linkStateMachine->AddStateToGameStateList(LinkStates::Spawning, std::make_unique<LinkSpawningState>(this));
	_linkStateMachine->AddStateToGameStateList(LinkStates::Moving, std::make_unique<LinkMovingState>(this));
}
