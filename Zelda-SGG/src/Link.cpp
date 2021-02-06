#include "Link.h"
#include "PlayerController.h"
#include "animation/LinkAnimationController.h"
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
	_boxColliderComponent = std::make_unique<SG::BoxColliderComponent>(this);
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
			SG::ControllerButtons button = SG::ControllerButtons::Up;
			if (_inputComponent->CurrentController->IsButtonPressed(button) || _inputComponent->CurrentController->IsButtonHeld(button))
			{
				_animationComponent->IsAnimPlaying = true;
				_location.Y -=3;
				_animationComponent->ChangeAnimation(LinkAnimations::WalkUp);
			}
			button = SG::ControllerButtons::Down;
			 if (_inputComponent->CurrentController->IsButtonPressed(button) || _inputComponent->CurrentController->IsButtonHeld(button))
			{
				 _animationComponent->IsAnimPlaying = true;
				_location.Y+=3;
				_animationComponent->ChangeAnimation(LinkAnimations::WalkDown);


			}
			button = SG::ControllerButtons::Left;
			if (_inputComponent->CurrentController->IsButtonPressed(button) || _inputComponent->CurrentController->IsButtonHeld(button))
			{
				_animationComponent->IsAnimPlaying = true;

				_location.X-=3;
				_animationComponent->ChangeAnimation((LinkAnimations::WalkLeft));

			}
			button = SG::ControllerButtons::Right;
			if (_inputComponent->CurrentController->IsButtonPressed(button) || _inputComponent->CurrentController->IsButtonHeld(button))
			{
				_animationComponent->IsAnimPlaying = true;

				_location.X+=3;
				_animationComponent->ChangeAnimation(LinkAnimations::WalkRight);

			}


		}
	}
}
