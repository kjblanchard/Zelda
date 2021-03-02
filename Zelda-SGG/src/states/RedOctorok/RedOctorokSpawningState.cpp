#include "states/RedOctorok/RedOctorokSpawningState.h"
#include "characters/RedOctorok.h"
#include "animation/RedOctorokAnimations/RedOctorokAnimations.h"
#include "components/BoxColliderComponent.h"
#include "animation/RedOctorokAnimations/RedOctorokAnimationController.h"






RedOctorokSpawningState::RedOctorokSpawningState(RedOctorok* owner) : _redOctorok(owner)
{

}

void RedOctorokSpawningState::Startup()
{
	_redOctorok->_boxColliderComponent->Startup();
	_redOctorok->_animationComponent->Startup();
	_redOctorok->_animationComponent->ChangeAnimation(RedOctorokAnimations::WalkUp);
	_redOctorok->_animationComponent->IsAnimPlaying = true;
	//_redOctorok->_objectStateMachine->ChangeState(RedOctorokStates::Moving);
}

void RedOctorokSpawningState::Update(const double& deltaTime)
{
}

void RedOctorokSpawningState::Draw(SG::SpriteBatch& spriteBatch)
{
	if (SG::World::_isCollisionDebug)
		_redOctorok->_boxColliderComponent->Draw(spriteBatch);
}

void RedOctorokSpawningState::End()
{
}
