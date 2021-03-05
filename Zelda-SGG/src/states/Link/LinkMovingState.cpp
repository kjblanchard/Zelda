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
	if (!_link->_isInvincible)
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
	else
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
	//TODO fix this after the demo
	(!_link->_isInvincible) ? _link->_animationComponent->IsAnimPlaying = false : _link->_animationComponent->IsAnimPlaying = true;

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
				_link->_animationComponent->IsAnimPlaying = true;
				_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkUp);
				_link->_currentDirection = SG::Directions::Up;
				potentialMoveSpeed.Y -= _link->_speed;

			}
			else if (_link->_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::Down) || _link->_inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::Down))
			{
				_link->_animationComponent->IsAnimPlaying = true;
				_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkDown);
				_link->_currentDirection = SG::Directions::Down;

				potentialMoveSpeed.Y += _link->_speed;

			}
			else if (_link->_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::Left) || _link->_inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::Left))
			{
				_link->_animationComponent->IsAnimPlaying = true;
				_link->_animationComponent->ChangeAnimation((LinkAnimations::WalkLeft));
				_link->_currentDirection = SG::Directions::Left;
				potentialMoveSpeed.X -= _link->_speed;

			}
			else if (_link->_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::Right) || _link->_inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::Right))
			{
				_link->_animationComponent->IsAnimPlaying = true;
				_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkRight);
				_link->_currentDirection = SG::Directions::Right;
				potentialMoveSpeed.X += _link->_speed;

			}

			auto bbox = _link->_boxColliderComponent->ColliderBox();
			bbox.x += potentialMoveSpeed.X;
			bbox.y += potentialMoveSpeed.Y;
			auto* worldLevel = ZeldaLevel::GetLevel()->GetCurrentGameLevel();
			if (!worldLevel->IsThereACollision(bbox, SG::GameObjectTypes::SolidTile))
			{
				_link->_location.X += potentialMoveSpeed.X;
				_link->_location.Y += potentialMoveSpeed.Y;
			}
			else
			{
				if (worldLevel)
				{
					auto gameObject = worldLevel->ReturnFirstCollisionGameObject(bbox, SG::GameObjectTypes::SolidTile);
					if (gameObject->Id)
					{
						const auto gameObjectColliderbox = gameObject->GetComponent<SG::BoxColliderComponent>()->ColliderBox();

						const auto collisionArea = SG::Collision::ShapeIntersectionArea(&bbox, &gameObjectColliderbox);
						switch (SG::Collision::CalculateIntersectionDirection(collisionArea, bbox))
						{
						case SG::Directions::Up:
							_link->_location.Y += potentialMoveSpeed.Y += collisionArea.h;
							break;
						case SG::Directions::Right:
							_link->_location.X += potentialMoveSpeed.X -= collisionArea.w;
							break;
						case SG::Directions::Down:
							_link->_location.Y += potentialMoveSpeed.Y -= collisionArea.h;
							break;
						case SG::Directions::Left:
							_link->_location.X += potentialMoveSpeed.X += collisionArea.w;
							break;
						}
					}


				}
			}
			if (!worldLevel->IsThereACollision(bbox, SG::GameObjectTypes::Enemy))
			{
				//dosomething?
			}
			else
			{
				if (worldLevel)
				{
					auto enemy = worldLevel->ReturnFirstCollisionGameObject(bbox, SG::GameObjectTypes::Enemy);
					if (enemy->Id)
					{
						const auto gameObjectColliderbox = enemy->GetComponent<SG::BoxColliderComponent>()->ColliderBox();

						const auto collisionArea = SG::Collision::ShapeIntersectionArea(&bbox, &gameObjectColliderbox);
						if (!_link->_isInvincible)
						{
							//switch (SG::Collision::CalculateIntersectionDirection(collisionArea, bbox))
							//{
							//case SG::Directions::Up:
							//	_link->_location.Y += potentialMoveSpeed.Y += 50;
							//	break;
							//case SG::Directions::Right:
							//	_link->_location.X += potentialMoveSpeed.X -= 50;
							//	break;
							//case SG::Directions::Down:
							//	_link->_location.Y += potentialMoveSpeed.Y -= 50;
							//	break;
							//case SG::Directions::Left:
							//	_link->_location.X += potentialMoveSpeed.X += 50;
							//	break;
							//}
							auto* convertedToTakingDamage = dynamic_cast<IGiveDamage*>(enemy);
							if (convertedToTakingDamage)
							{
								_link->TakeDamage(convertedToTakingDamage->GiveDamage());
							}
						}
					}
				}
			}

		}
	}
}

void LinkMovingState::End()
{
}
