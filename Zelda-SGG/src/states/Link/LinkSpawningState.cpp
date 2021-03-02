#include "states/Link/LinkSpawningState.h"
#include "characters/Link.h"
#include "animation/LinkAnimations/LinkAnimationController.h"
#include "components/BoxColliderComponent.h"
#include "states/Link/LinkStates.h"

LinkSpawningState::LinkSpawningState(Link* link) : _link(link)
{
}

void LinkSpawningState::Startup()
{
	_link->_animationComponent->Startup();
	_link->_boxColliderComponent->Startup();
	_link->_objectStateMachine->ChangeState(LinkStates::Moving);

}

void LinkSpawningState::Update(const double& deltaTime)
{
}

void LinkSpawningState::Draw(SG::SpriteBatch& spriteBatch)
{
}

void LinkSpawningState::End()
{
}
