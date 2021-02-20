#include "states/Link/LinkAttackingState.h"

#include <SDL_timer.h>

#include "data/Directions.h"
#include "animation/LinkAnimations/LinkAnimationController.h"
#include "characters/Link.h"
#include "states/Link/LinkStates.h"


void LinkAttackingState::Startup()
{
 	_link->_animationComponent->IsAnimPlaying = true;
	switch (_link->_currentDirection)
	{
	case SG::Directions::Up:
		_link->_animationComponent->ChangeAnimation(LinkAnimations::AttackUp);
		break;
	case SG::Directions::Right:
		_link->_animationComponent->ChangeAnimation(LinkAnimations::AttackRight);
		break;
	case SG::Directions::Down:
		_link->_animationComponent->ChangeAnimation(LinkAnimations::AttackDown);
		break;
	case SG::Directions::Left:
		_link->_animationComponent->ChangeAnimation(LinkAnimations::AttackLeft);
		break;
	}
	_link->ChangeState(LinkStates::Moving);
	//SDL_AddTimer(1000, Callback, this);

}

void LinkAttackingState::Update(const double& deltaTime)
{
}

void LinkAttackingState::Draw(SG::SpriteBatch& spriteBatch)
{
}

void LinkAttackingState::End()
{
}

Uint32 LinkAttackingState::Callback(Uint32 interval, void* param)
{
	auto link = static_cast<Link*>(param);
	link->ChangeState(LinkStates::Moving);
	return 0;

}
