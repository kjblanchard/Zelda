#include "states/Link/LinkAttackingState.h"
#include "data/Directions.h"
#include "animation/LinkAnimations/LinkAnimationController.h"
#include "characters/Link.h"
#include "states/Link/LinkStates.h"


void LinkAttackingState::Startup()
{
 	//_link->_animationComponent->IsAnimPlaying = true;
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

}

void LinkAttackingState::Update(const double& deltaTime)
{
	_timeInState += deltaTime;
	if (_timeInState >= _maxTimeInState)
		_link->ChangeState(LinkStates::Moving);
}

void LinkAttackingState::Draw(SG::SpriteBatch& spriteBatch)
{
}

void LinkAttackingState::End()
{
	_timeInState = 0;
}


