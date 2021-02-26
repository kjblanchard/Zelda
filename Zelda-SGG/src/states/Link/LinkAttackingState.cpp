#include "states/Link/LinkAttackingState.h"

#include "Sound.h"
#include "ZeldaLevel.h"
#include "data/Directions.h"
#include "animation/LinkAnimations/LinkAnimationController.h"
#include "characters/Link.h"
#include "states/Link/LinkStates.h"
#include "../WoodSwordWeapon.h"
#include "components/BoxColliderComponent.h"
#include "GameLevel.h"
#include "Sound.h"


void LinkAttackingState::Startup()
{

	auto newLoc = SG::Vector3(0);
	switch (_link->_currentDirection)
	{
	case SG::Directions::Up:
		 newLoc = SG::Vector3(_link->Location().X, _link->Location().Y - 32);
		woodSwordDisplay = new WoodSwordWeapon(newLoc, _link);
		woodSwordDisplay->Startup();
		_link->_animationComponent->ChangeAnimation(LinkAnimations::AttackUp);
		break;
	case SG::Directions::Right:
		 newLoc = SG::Vector3(_link->Location().X + 32, _link->Location().Y);
		woodSwordDisplay = new WoodSwordWeapon(newLoc, _link);
		woodSwordDisplay->Startup();
		_link->_animationComponent->ChangeAnimation(LinkAnimations::AttackRight);
		break;
	case SG::Directions::Down:
		newLoc = SG::Vector3(_link->Location().X, _link->Location().Y + 32);
		woodSwordDisplay = new WoodSwordWeapon(newLoc, _link);
		woodSwordDisplay->Startup();
		_link->_animationComponent->ChangeAnimation(LinkAnimations::AttackDown);
		break;
	case SG::Directions::Left:
		newLoc = SG::Vector3(_link->Location().X -32, _link->Location().Y);
		woodSwordDisplay = new WoodSwordWeapon(newLoc, _link);
		woodSwordDisplay->Startup();
		_link->_animationComponent->ChangeAnimation(LinkAnimations::AttackLeft);
		break;
	}
	SG::Sound::PlaySound(SG::SoundFxToPlay::BaseSwordAttack);
}

void LinkAttackingState::Update(const double& deltaTime)
{
	_timeInState += deltaTime;
	if (_timeInState >= _maxTimeInState)
		_link->ChangeState(LinkStates::Moving);
	if (woodSwordDisplay)
	{
		woodSwordDisplay->Update(deltaTime);
		auto bbox = woodSwordDisplay->BoxColliderComp->ColliderBox;

		auto* worldLevel = ZeldaLevel::GetLevel()->GetCurrentGameLevel();

		woodSwordDisplay->BoxColliderComp->previousFrameCollisions = woodSwordDisplay->BoxColliderComp->currentFrameCollisions;

		woodSwordDisplay->BoxColliderComp->currentFrameCollisions = worldLevel->ReturnAllCollisions(bbox, SG::GameObjectTypes::SolidTile);

		for (auto cu : woodSwordDisplay->BoxColliderComp->currentFrameCollisions)
		{
			if(woodSwordDisplay->BoxColliderComp->CheckIfJustIntersected(cu->Id))
				SG::Sound::PlaySound(SG::SoundFxToPlay::EnemyKill);
		}
	}



}

void LinkAttackingState::Draw(SG::SpriteBatch& spriteBatch)
{
	if(woodSwordDisplay)
		woodSwordDisplay->Draw(spriteBatch);
}

void LinkAttackingState::End()
{
	_timeInState = 0;
	delete woodSwordDisplay;
	woodSwordDisplay = nullptr;
}


