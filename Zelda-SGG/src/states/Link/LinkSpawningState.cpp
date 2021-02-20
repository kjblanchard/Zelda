#include "states/Link/LinkSpawningState.h"
#include "Link.h"
#include "animation/LinkAnimationController.h"
#include "components/BoxColliderComponent.h"
#include "states/Link/LinkStates.h"

LinkSpawningState::LinkSpawningState(Link* link) : _link(link)
{
}

void LinkSpawningState::Startup()
{
	_link->_animationComponent->Startup();
	_link->_boxColliderComponent->Startup();
	_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkDown);
	_link->_linkStateMachine->ChangeState(LinkStates::Moving);

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
