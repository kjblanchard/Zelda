#include "states/Link/LinkHitState.h"
#include "characters/Link.h"
#include "animation/LinkAnimations/LinkAnimations.h"
#include "data/Directions.h"
#include "states/Link/LinkStates.h"
#include "animation/LinkAnimations/LinkAnimationController.h"

void LinkHitState::Startup()
{
	switch (_link->_currentDirection)
	{
	case SG::Directions::Up:
		_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkHitUp);
		break;
	case SG::Directions::Right:
		_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkHitRight);
		break;
	case SG::Directions::Down:
		_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkHitDown);
		break;
	case SG::Directions::Left:
		_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkHitRight);
		break;
	}
}

void LinkHitState::Update(const double& deltaTime)
{
	if (_link->_knockBackAmount >= 0)
	{
		auto movementAmount = 10;
		_link->_location.X -= movementAmount;
		_link->UpdateKnockBackAmount(movementAmount);
	}
	if(_link->_knockBackAmount <= 0)
	{
		_link->_knockBackAmount = 0;
		_link->ChangeState(LinkStates::Moving);
	}
}

void LinkHitState::Draw(SG::SpriteBatch& spriteBatch)
{
}

void LinkHitState::End()
{
}
