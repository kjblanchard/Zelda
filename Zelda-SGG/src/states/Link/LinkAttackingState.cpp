#include "states/Link/LinkAttackingState.h"
#include "core/Sound.h"
#include "ZeldaLevel.h"
#include "data/Directions.h"
#include "animation/LinkAnimations/LinkAnimationController.h"
#include "characters/Link.h"
#include "states/Link/LinkStates.h"
#include "items/WoodSwordWeapon.h"
#include "components/BoxColliderComponent.h"
#include "core/GameLevel.h"


void LinkAttackingState::Startup()
{
	woodSwordDisplay = new WoodSwordWeapon(_link->Location(), _link);
	woodSwordDisplay->Startup();

	switch (_link->_currentDirection)
	{
	case SG::Directions::Up:
		_link->_animationComponent->ChangeAnimation(LinkAnimations::AttackUp);
		break;
	case SG::Directions::Right:
		_link->_animationComponent->ChangeAnimation(LinkAnimations::AttackRight);
		break;
	case SG::Directions::Down:
		_link->_animationComponent->ChangeAnimation(LinkAnimations::AttackDown);
		break;
	case SG::Directions::Left:
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
		woodSwordDisplay->BoxColliderComp->GatherAllCurrentIntersections(ZeldaLevel::GetLevel()->GetCurrentGameLevel(), SG::GameObjectTypes::SolidTile);
		woodSwordDisplay->BoxColliderComp->CallFunctionOnEachJustIntersected(PlaySoundOnHit);
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


