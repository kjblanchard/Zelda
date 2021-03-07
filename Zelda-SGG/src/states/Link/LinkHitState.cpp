#include "states/Link/LinkHitState.h"
#include "characters/Link.h"
#include "animation/LinkAnimations/LinkAnimations.h"
#include "data/Directions.h"
#include "states/Link/LinkStates.h"
#include "animation/LinkAnimations/LinkAnimationController.h"

void LinkHitState::Startup()
{

}

void LinkHitState::Update(const double& deltaTime)
{
	if (_link->_knockBackAmount > 0)
	{
		switch (_link->_knockBackDirection)
		{
		case SG::Directions::Up:
			_link->_location.Y += _link->_knockBackAmountPerFrame;
			break;
		case SG::Directions::Right:
			_link->_location.X -= _link->_knockBackAmountPerFrame;
			break;
		case SG::Directions::Down:
			_link->_location.Y -= _link->_knockBackAmountPerFrame;
			break;
		case SG::Directions::Left:
			_link->_location.X += _link->_knockBackAmountPerFrame;
			break;
		}
		_link->UpdateKnockBackAmount(_link->_knockBackAmountPerFrame);
	}

	if (_link->_knockBackAmount <= 0)
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
