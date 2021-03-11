#include "states/Link/LinkMovingState.h"
#include "components/InputComponent.h"
#include "input/Controller.h"
#include "characters/Link.h"
#include "ZeldaLevel.h"
#include "collision/Collision.h"
#include "core/GameLevel.h"
#include "components/BoxColliderComponent.h"
#include "animation/LinkAnimations/LinkAnimationController.h"
#include "characters/RedOctorok.h"
#include "states/Link/LinkStates.h"
#include "interfaces/IGiveDamage.h"

LinkMovingState::LinkMovingState(Link* link) : _link(link)
{
}

void LinkMovingState::Startup()
{
		switch (_link->_currentDirection)
		{
		case SG::Directions::Up:
			_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkUp);
			break;
		case SG::Directions::Right:
			_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkRight);
			break;
		case SG::Directions::Down:
			_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkDown);
			break;
		case SG::Directions::Left:
			_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkLeft);
			break;
		}
}

void LinkMovingState::Update(const double& deltaTime)
{
	HandleInput();
}

void LinkMovingState::Draw(SG::SpriteBatch& spriteBatch)
{
}

void LinkMovingState::HandleInput()
{
	_link->_animationComponent->IsAnimPlaying = true;
	_link->_isMoving = false;

	if (_link->_inputComponent)
	{

		if (_link->_inputComponent->CurrentController)
		{
			auto potentialMoveSpeed = SG::Point(0, 0);

			if (_link->_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::A) || _link->_inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::A))
			{
				_link->_objectStateMachine->ChangeState(LinkStates::Attacking);
			}

			else if (_link->_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::Up) || _link->_inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::Up))
			{
				HandleMovement(SG::Directions::Up, potentialMoveSpeed);

			}
			else if (_link->_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::Down) || _link->_inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::Down))
			{
				HandleMovement(SG::Directions::Down, potentialMoveSpeed);

			}
			else if (_link->_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::Left) || _link->_inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::Left))
			{
				HandleMovement(SG::Directions::Left, potentialMoveSpeed);

			}
			else if (_link->_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::Right) || _link->_inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::Right))
			{
				HandleMovement(SG::Directions::Right, potentialMoveSpeed);
			}

			HandleSolidTileCollisions(potentialMoveSpeed);
			HandleEnemyCollisions();
		}
	}
}

void LinkMovingState::End()
{
}

void LinkMovingState::HandleMovement(SG::Directions direction, SG::Point& outPotentialMove) const
{
	_link->_isMoving = true;
	switch (direction)
	{
	case SG::Directions::Up:
		_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkUp);
		_link->_currentDirection = SG::Directions::Up;
		outPotentialMove.Y -= _link->_speed;
		break;
	case SG::Directions::Right:
		_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkRight);
		_link->_currentDirection = SG::Directions::Right;
		outPotentialMove.X += _link->_speed;
		break;
	case SG::Directions::Down:
		_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkDown);
		_link->_currentDirection = SG::Directions::Down;

		outPotentialMove.Y += _link->_speed;
		break;
	case SG::Directions::Left:
		_link->_animationComponent->ChangeAnimation((LinkAnimations::WalkLeft));
		_link->_currentDirection = SG::Directions::Left;
		outPotentialMove.X -= _link->_speed;
		break;
	}
}

void LinkMovingState::HandleSolidTileCollisions(SG::Point potentialMove) const
{
	const auto newPotentialMove = _link->HandleSolidTileCollision(_link->_boxColliderComponent->ColliderBox(), potentialMove);
	_link->_location += newPotentialMove;
}

void LinkMovingState::HandleEnemyCollisions() const
{
	auto* const enemy = _link->PlayerHandleEnemyCollision(_link->_boxColliderComponent->ColliderBox());
	if (enemy)
	{
		if (!_link->_isInvincible)
		{
			auto* convertedToTakingDamage = dynamic_cast<IGiveDamage*>(enemy);
			if (convertedToTakingDamage)
			{
				_link->TakeDamage(convertedToTakingDamage->GiveDamage());
			}
		}
	}
}


