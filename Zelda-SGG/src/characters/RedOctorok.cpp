#include "characters/RedOctorok.h"
#include "components/BoxColliderComponent.h"
#include "animation/RedOctorokAnimations/RedOctorokAnimationController.h"
#include "animation/RedOctorokAnimations/RedOctorokAnimations.h"
#include "states/RedOctorok/RedOctorokStates.h"
#include "states/RedOctorok/RedOctorokSpawningState.h"
#include "states/RedOctorok/RedOctorokMovingState.h"


RedOctorok::RedOctorok(SG::Vector3 location) : GameObject(location,SG::GameObjectTypes::Enemy), IGiveDamage( new Damage{10,50,this}), ITakeDamage(20), _boxColliderComponent(nullptr)
{
	_animationComponent = std::make_unique<SG::AnimationComponent<RedOctorokAnimationController, RedOctorokAnimations>>(this, new RedOctorokAnimationController(this));
	auto boxColliderBox = SDL_Rect{ 0,0,30,30 };
	_boxColliderComponent = std::make_unique<SG::BoxColliderComponent>(this, boxColliderBox, true);
	_baseDamage->BoxColliderOfDamageGiver = _boxColliderComponent->ColliderBox();
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
	_animationComponent->Update(deltaTime);
	_boxColliderComponent->Update(deltaTime);
}

void RedOctorok::GenerateStates()
{
	_objectStateMachine->AddStateToGameStateList(RedOctorokStates::Spawning, std::make_unique<RedOctorokSpawningState>(this));
	_objectStateMachine->AddStateToGameStateList(RedOctorokStates::Moving, std::make_unique<RedOctorokMovingState>(this));

}

Damage* RedOctorok::GiveDamage()
{
	return _baseDamage;
}

void RedOctorok::TakeDamage(Damage* damage)
{

}
