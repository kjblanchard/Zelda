#include "states/Link/LinkMovingState.h"
#include "components/InputComponent.h"
#include "Controller.h"
#include "Link.h"
#include "ZeldaLevel.h"
#include "collision/Collision.h"
#include "GameLevel.h"
#include "components/BoxColliderComponent.h"
#include "animation/LinkAnimationController.h"

LinkMovingState::LinkMovingState(Link* link) : _link(link)
{
}

void LinkMovingState::Startup()
{
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
	_link->_animationComponent->IsAnimPlaying = false;
	if (_link->_inputComponent)
	{

		if (_link->_inputComponent->CurrentController)
		{
			auto potentialMoveSpeed = SG::Point(0, 0);

			if (_link->_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::Up) || _link->_inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::Up))
			{
				_link->_animationComponent->IsAnimPlaying = true;
				_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkUp);
				potentialMoveSpeed.Y -= 3;

			}
			else if (_link->_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::Down) || _link->_inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::Down))
			{
				_link->_animationComponent->IsAnimPlaying = true;
				_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkDown);
				potentialMoveSpeed.Y += 3;

			}
			else if (_link->_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::Left) || _link->_inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::Left))
			{
				_link->_animationComponent->IsAnimPlaying = true;
				_link->_animationComponent->ChangeAnimation((LinkAnimations::WalkLeft));
				potentialMoveSpeed.X -= 3;

			}
			else if (_link->_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::Right) || _link->_inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::Right))
			{
				_link->_animationComponent->IsAnimPlaying = true;
				_link->_animationComponent->ChangeAnimation(LinkAnimations::WalkRight);
				potentialMoveSpeed.X += 3;

			}

			auto bbox = _link->_boxColliderComponent->ColliderBox;
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
					if (gameObject.Id)
					{
						const auto gameObjectColliderbox = gameObject.GetComponent<SG::BoxColliderComponent>()->ColliderBox;

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
		}
	}
}

void LinkMovingState::End()
{
}
