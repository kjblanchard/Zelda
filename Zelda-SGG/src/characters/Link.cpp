#include "characters/Link.h"
#include "ZeldaConfig.h"
#include "ZeldaWorld.h"
#include "models/CharacterModel.h"
#include "structs/Damage.h"
#include "components/InputComponent.h"
#include "components/BoxColliderComponent.h"
#include "animation/LinkAnimations/LinkAnimationController.h"
#include "collision/Collision.h"
#include "data/Directions.h"
#include "states/Link/LinkStates.h"
#include "states/Link/LinkSpawningState.h"
#include "states/Link/LinkMovingState.h"
#include "states/Link/LinkAttackingState.h"
#include "states/Link/LinkHitState.h"


Link::Link(SG::Vector3 location)
	:
	GameObject(location),
	ITakeDamage(ZeldaConfig::ZeldaStats.LinkBaseStats.MaxHp, ZeldaConfig::ZeldaStats.LinkBaseStats.InvincibilityTime),
	IGiveDamage(new Damage{
		ZeldaConfig::ZeldaStats.WoodSwordBaseStats.Damage, ZeldaConfig::ZeldaStats.WoodSwordBaseStats.Knockback, this
	}),
	_speed(ZeldaConfig::ZeldaStats.LinkBaseStats.Speed), _animationComponent(nullptr), _inputComponent(nullptr)
{
	_currentDirection = SG::Directions::Down;
	_animationComponent = std::make_unique<SG::AnimationComponent<LinkAnimationController, LinkAnimations>>(
		this, new LinkAnimationController(this));
	auto boxColliderBox = SDL_Rect{
		ZeldaConfig::ZeldaStats.LinkBaseStats.HitboxXOffset, ZeldaConfig::ZeldaStats.LinkBaseStats.HitboxYOffset,
		ZeldaConfig::ZeldaStats.LinkBaseStats.HitboxWidth, ZeldaConfig::ZeldaStats.LinkBaseStats.HitboxHeight
	};
	_boxColliderComponent = std::make_unique<SG::BoxColliderComponent>(this,boxColliderBox, true);
}

Link::Link(SG::Vector3 location, SG::Controller* controller)
	: Link(location)
{
	_inputComponent = std::make_unique<SG::InputComponent>(controller, this);
}

void Link::Startup()
{
	_animationComponent->Startup();
	_boxColliderComponent->Startup();
	GenerateStates();
	_objectStateMachine->ChangeState(LinkStates::Spawning);
}

void Link::Update(const double& deltaTime)
{
	ComponentUpdate(deltaTime);
}

void Link::Draw(SG::SpriteBatch& spriteBatch)
{
	_objectStateMachine->Draw(spriteBatch);
	_animationComponent->Draw(spriteBatch);
	_boxColliderComponent->Draw(spriteBatch);

}

void Link::ComponentUpdate(const double& deltaTime)
{
	_objectStateMachine->Update(deltaTime);
	//TODO should update invincibility time be here?
	UpdateInvincibilityTime(deltaTime);
	_animationComponent->Update(deltaTime);
	_boxColliderComponent->Update(deltaTime);
}


void Link::GenerateStates()
{
	_objectStateMachine->AddStateToGameStateList(LinkStates::Spawning, std::make_unique<LinkSpawningState>(this));
	_objectStateMachine->AddStateToGameStateList(LinkStates::Moving, std::make_unique<LinkMovingState>(this));
	_objectStateMachine->AddStateToGameStateList(LinkStates::Attacking, std::make_unique<LinkAttackingState>(this));
	_objectStateMachine->AddStateToGameStateList(LinkStates::TakingDamage, std::make_unique<LinkHitState>(this));
}

void Link::TakeDamage(Damage* damage)
{
	if (!_isInvincible)
	{
		auto bbox = _boxColliderComponent->ColliderBox();
		const auto gameObjectColliderbox = damage->GameObjectCausingDamage->GetComponent<SG::BoxColliderComponent>()->ColliderBox();
		const auto collisionArea = SG::Collision::ShapeIntersectionArea(&bbox, &gameObjectColliderbox);
		_knockBackDirection = SG::Collision::CalculateIntersectionDirection(collisionArea, bbox);

		_knockBackAmount = damage->PushbackAmount;
		_knockBackAmountPerFrame = _knockBackAmount / 5;
		SetInvincibilityTimer();
		ApplyDamage(damage->DamageAmount);
		SG::Sound::PlaySound(SG::SoundFxToPlay::LinkHurt);
		ChangeState(LinkStates::TakingDamage);
	}

}
