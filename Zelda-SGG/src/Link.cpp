#include "Link.h"

#include "DebugRoomLevel.h"
#include "PlayerController.h"
#include "ZeldaWorld.h"
#include "animation/LinkAnimationController.h"
#include "collision/Collision.h"
#include "components/InputComponent.h"
#include "components/AnimationComponent.h"
#include "components/BoxColliderComponent.h"
#include "data/Vector3.h"



Link::Link(SG::Vector3 location)
	: GameObject(location), _animationComponent(nullptr),_inputComponent(nullptr)
{
}

Link::Link(SG::Vector3 location, SG::Controller* controller)
	: Link(location)
{
	_inputComponent = std::make_unique<SG::InputComponent>(controller, this);
	_animationComponent = std::make_unique<SG::AnimationComponent<LinkAnimationController, LinkAnimations>>(this, new LinkAnimationController(this));
	auto boxColliderBox = SDL_Rect{ 0,0,24,24 };
	_boxColliderComponent = std::make_unique<SG::BoxColliderComponent>(this,boxColliderBox);
}

Link::~Link()
{
}


void Link::Startup()
{
	_animationComponent->Startup();
	_animationComponent->ChangeAnimation(LinkAnimations::WalkDown);
	_boxColliderComponent->Startup();
}

void Link::Update(const double& deltaTime)
{
	HandleInput();
	ComponentUpdate(deltaTime);
}

void Link::Draw(SG::SpriteBatch& spriteBatch)
{
	_animationComponent->Draw(spriteBatch);
	_boxColliderComponent->Draw(spriteBatch);

}

void Link::ComponentUpdate(const double& deltaTime)
{
	_animationComponent->Update(deltaTime);
	_boxColliderComponent->Update(deltaTime);
}


void Link::HandleInput()
{
	_animationComponent->IsAnimPlaying = false;
	if(_inputComponent)
	{

		if(_inputComponent->CurrentController)
		{
			auto potentialMoveSpeed = SG::Point(0, 0);

			if (_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::Up) || _inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::Up))
			{
				_animationComponent->IsAnimPlaying = true;
				_animationComponent->ChangeAnimation(LinkAnimations::WalkUp);
				potentialMoveSpeed.Y -= 3;

			}
			else if (_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::Down) || _inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::Down))
			{
				 _animationComponent->IsAnimPlaying = true;
				_animationComponent->ChangeAnimation(LinkAnimations::WalkDown);
				potentialMoveSpeed.Y += 3;

			}
			else if (_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::Left) || _inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::Left))
			{
				_animationComponent->IsAnimPlaying = true;
				_animationComponent->ChangeAnimation((LinkAnimations::WalkLeft));
				potentialMoveSpeed.X -= 3;

			}
			else if (_inputComponent->CurrentController->IsButtonPressed(SG::ControllerButtons::Right) || _inputComponent->CurrentController->IsButtonHeld(SG::ControllerButtons::Right))
			{
				_animationComponent->IsAnimPlaying = true;
				_animationComponent->ChangeAnimation(LinkAnimations::WalkRight);
				potentialMoveSpeed.X += 3;

			}

			auto bbox = _boxColliderComponent->ColliderBox;
			bbox.x += potentialMoveSpeed.X;
			bbox.y += potentialMoveSpeed.Y;
				auto* worldLevel = ZeldaLevel::GetLevel()->GetCurrentGameLevel();
			if(!worldLevel->IsThereACollision(bbox,SG::GameObjectTypes::SolidTile))
			{
				_location.X += potentialMoveSpeed.X;
				_location.Y += potentialMoveSpeed.Y;
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
							_location.Y += potentialMoveSpeed.Y += collisionArea.h;
							break;
						case SG::Directions::Right:
							_location.X += potentialMoveSpeed.X -= collisionArea.w;
							break;
						case SG::Directions::Down:
							_location.Y += potentialMoveSpeed.Y -= collisionArea.h;
							break;
						case SG::Directions::Left:
							_location.X += potentialMoveSpeed.X += collisionArea.w;
							break;
						}
					}

				}
			}
		}
	}
}
