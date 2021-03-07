#include "characters/RedOctorok.h"

#include "ZeldaConfig.h"
#include "components/BoxColliderComponent.h"
#include "animation/RedOctorokAnimations/RedOctorokAnimationController.h"
#include "animation/RedOctorokAnimations/RedOctorokAnimations.h"
#include "collision/Collision.h"
#include "core/Sound.h"
#include "models/WeaponModel.h"
#include "states/RedOctorok/RedOctorokStates.h"
#include "states/RedOctorok/RedOctorokSpawningState.h"
#include "states/RedOctorok/RedOctorokMovingState.h"
#include "states/RedOctorok/RedOctorokHitState.h"


RedOctorok::RedOctorok(SG::Vector3 location) : GameObject(location,SG::GameObjectTypes::Enemy), IGiveDamage( new Damage{ZeldaConfig::WoodBallBaseStats.Damage,ZeldaConfig::WoodBallBaseStats.Knockback,this}), ITakeDamage(20,ZeldaConfig::RedOctoBaseStats.InvincibilityTime), _boxColliderComponent(nullptr)
{
	_animationComponent = std::make_unique<SG::AnimationComponent<RedOctorokAnimationController, RedOctorokAnimations>>(this, new RedOctorokAnimationController(this));
	auto boxColliderBox = SDL_Rect{ 0,0,30,30 };
	_boxColliderComponent = std::make_unique<SG::BoxColliderComponent>(this, boxColliderBox, true);
}

void RedOctorok::Startup()
{
	GenerateStates();
	_objectStateMachine->ChangeState(RedOctorokStates::Spawning);
	std::cout << _baseDamage->DamageAmount;
}

void RedOctorok::Update(const double& deltaTime)
{
	_objectStateMachine->Update(deltaTime);
	ComponentUpdate(deltaTime);
}

void RedOctorok::Draw(SG::SpriteBatch& spriteBatch)
{
	_objectStateMachine->Draw(spriteBatch);
	_animationComponent->Draw(spriteBatch);

}

void RedOctorok::ComponentUpdate(const double& deltaTime)
{
	UpdateInvincibilityTime(deltaTime);
	_animationComponent->Update(deltaTime);
	_boxColliderComponent->Update(deltaTime);
}

void RedOctorok::GenerateStates()
{
	_objectStateMachine->AddStateToGameStateList(RedOctorokStates::Spawning, std::make_unique<RedOctorokSpawningState>(this));
	_objectStateMachine->AddStateToGameStateList(RedOctorokStates::Moving, std::make_unique<RedOctorokMovingState>(this));
	_objectStateMachine->AddStateToGameStateList(RedOctorokStates::TakingDamage, std::make_unique<RedOctorokHitState>(this));

}

Damage* RedOctorok::GiveDamage()
{
	return _baseDamage;
}

void RedOctorok::TakeDamage(Damage* damage)
{
	if(!_isInvincible)
	{

		auto bbox = _boxColliderComponent->ColliderBox();
		const auto gameObjectColliderbox = damage->GameObjectCausingDamage->GetComponent<SG::BoxColliderComponent>()->ColliderBox();
		const auto collisionArea = SG::Collision::ShapeIntersectionArea(&bbox, &gameObjectColliderbox);
		_knockBackDirection = SG::Collision::CalculateIntersectionDirection(collisionArea, bbox);

		_knockBackAmount = damage->PushbackAmount;
		_knockBackAmountPerFrame = _knockBackAmount / 5;
		SetInvincibilityTimer();
		ApplyDamage(damage->DamageAmount);
		SG::Sound::PlaySound(SG::SoundFxToPlay::EnemyKill);
		ChangeState(RedOctorokStates::TakingDamage);

	}
}
