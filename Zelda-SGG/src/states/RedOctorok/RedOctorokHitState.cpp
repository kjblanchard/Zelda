#include "states/RedOctorok/RedOctorokHitState.h"

#include "characters/RedOctorok.h"
#include "data/Directions.h"
#include "states/RedOctorok/RedOctorokStates.h"

void RedOctorokHitState::Startup()
{
}

void RedOctorokHitState::Update(const double& deltaTime)
{
	if (_redOcto->_knockBackAmount > 0)
	{
		switch (_redOcto->_knockBackDirection)
		{
		case SG::Directions::Up:
			_redOcto->_location.Y += _redOcto->_knockBackAmountPerFrame;
			break;
		case SG::Directions::Right:
			_redOcto->_location.X -= _redOcto->_knockBackAmountPerFrame;
			break;
		case SG::Directions::Down:
			_redOcto->_location.Y -= _redOcto->_knockBackAmountPerFrame;
			break;
		case SG::Directions::Left:
			_redOcto->_location.X += _redOcto->_knockBackAmountPerFrame;
			break;
		}
		_redOcto->UpdateKnockBackAmount(_redOcto->_knockBackAmountPerFrame);
	}

	if (_redOcto->_knockBackAmount <= 0)
	{
		_redOcto->_knockBackAmount = 0;
		_redOcto->ChangeState(RedOctorokStates::Moving);
	}
}

void RedOctorokHitState::Draw(SG::SpriteBatch& spriteBatch)
{
}

void RedOctorokHitState::End()
{
}
