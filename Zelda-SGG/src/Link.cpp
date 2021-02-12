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
#include "components/Component.h"
#include "../../SGGEngine/GameLevel.h"



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

bool Link::CheckForCollisions(SDL_Rect& potentialMove)
{
	auto worldLevel = dynamic_cast<SG::GameLevel*>(ZeldaLevel::GetLevel()->LevelStateMachine.CurrentState());

	if(worldLevel)
	{
		if (worldLevel->IsThereACollision(potentialMove, SG::GameObjectTypes::SolidTile))
			return true;
	}
	return false;
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

			////if(!CheckForCollisions(SDL_Rect()))
			auto bbox = _boxColliderComponent->ColliderBox;
			bbox.x += potentialMoveSpeed.X;
			bbox.y += potentialMoveSpeed.Y;
			if (!CheckForCollisions(bbox))
			{
				_location.X += potentialMoveSpeed.X;
				_location.Y += potentialMoveSpeed.Y;
			}
			else
			{
				auto* worldLevel = dynamic_cast<SG::GameLevel*>(ZeldaLevel::GetLevel()->LevelStateMachine.CurrentState());

				if (worldLevel)
				{
					auto go = worldLevel->ReturnFirstCollisionGameObject(bbox, SG::GameObjectTypes::SolidTile);
					auto collisionArea = SG::Collision::ShapeIntersectionArea(bbox, go.GetComponent<SG::BoxColliderComponent>()->ColliderBox);

					if(collisionArea.w < collisionArea.h)
					{
						if(collisionArea.x > bbox.x)
						{
							printf("right collision");
							_location.X += potentialMoveSpeed.X -= collisionArea.w;
						}
						else
						{
							printf("left collision");
							_location.X += potentialMoveSpeed.X += collisionArea.w;
						}
					}
					else
					{
						if(collisionArea.y > bbox.y)
						{
							printf("bottom collision");
							_location.Y += potentialMoveSpeed.Y -= collisionArea.h;
						}
						else
						{
							printf("top collision");
							_location.Y += potentialMoveSpeed.Y += collisionArea.h;

						}
					}
					//_location.X += potentialMoveSpeed.X - collisionArea.w;
					//_location.Y += potentialMoveSpeed.Y - collisionArea.h;
				}
			}
		}
	}
}
