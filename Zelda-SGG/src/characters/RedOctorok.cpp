#include "characters/RedOctorok.h"
#include <SDL_rect.h>
#include "components/BoxColliderComponent.h"
#include "states/RedOctorok/RedOctorokStates.h"
#include "animation/RedOctorokAnimations/RedOctorokAnimationController.h"
#include "animation/RedOctorokAnimations/RedOctorokAnimations.h"



RedOctorok::RedOctorok(SG::Vector3 location) : GameObject(location,SG::GameObjectTypes::Enemy),_boxColliderComponent(nullptr)
{
	_animationComponent = std::make_unique<SG::AnimationComponent<RedOctorokAnimationController, RedOctorokAnimations>>(this, new RedOctorokAnimationController(this));
	auto boxColliderBox = SDL_Rect{ 0,0,30,30 };
	_boxColliderComponent = std::make_unique<SG::BoxColliderComponent>(this, boxColliderBox, true);
}

void RedOctorok::Startup()
{
	_boxColliderComponent->Startup();
	_animationComponent->Startup();
	GenerateStates();
	_animationComponent->ChangeAnimation(RedOctorokAnimations::WalkUp);
	_animationComponent->IsAnimPlaying = true;
}

void RedOctorok::Update(const double& deltaTime)
{
	_animationComponent->Update(deltaTime);
}

void RedOctorok::Draw(SG::SpriteBatch& spriteBatch)
{
	_animationComponent->Draw(spriteBatch);
	if (SG::World::_isCollisionDebug)
		_boxColliderComponent->Draw(spriteBatch);
}

void RedOctorok::ComponentUpdate(const double& deltaTime)
{
}

void RedOctorok::GenerateStates()
{
}
