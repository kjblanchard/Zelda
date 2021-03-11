#include "interfaces/ICharacterMovement.h"

#include "ZeldaLevel.h"
#include "collision/Collision.h"
#include "components/BoxColliderComponent.h"


SG::Point ICharacterMovement::HandleSolidTileCollision(SDL_Rect thisGuysColliderBox, SG::Point potentialMove)
{
	//Gets the current level
	currentGameLevel = ZeldaLevel::GetLevel()->GetCurrentGameLevel();

	//calculate the potential colliderbox
	thisGuysColliderBox.x += potentialMove.X;
	thisGuysColliderBox.y += potentialMove.Y;

	//If there is no colission, just return early, there is no handling of the x/y
	if (!currentGameLevel->IsThereACollision(thisGuysColliderBox, SG::GameObjectTypes::SolidTile))
		return potentialMove;

	//Calculate the new position
	auto collidedGameObject = currentGameLevel->ReturnFirstCollisionGameObject(thisGuysColliderBox, SG::GameObjectTypes::SolidTile);
	if (!collidedGameObject)
		SG::DebugHandler::PrintErrorMessage(SG::ErrorCodes::CollisionError, 1);
	auto gameObjectColliderbox = collidedGameObject->GetComponent<SG::BoxColliderComponent>()->ColliderBox();
	auto collisionArea = SG::Collision::ShapeIntersectionArea(&thisGuysColliderBox, &gameObjectColliderbox);
	switch(SG::Collision::CalculateIntersectionDirection(collisionArea,thisGuysColliderBox))
	{
	case SG::Directions::Up:
		potentialMove.Y += collisionArea.h;
		break;
	case SG::Directions::Right:
		potentialMove.X -= collisionArea.w;
		break;
	case SG::Directions::Down:
		potentialMove.Y -= collisionArea.h;
		break;
	case SG::Directions::Left:
		potentialMove.X += collisionArea.w;
		break;
	}
	return potentialMove;

}

SG::GameObject* ICharacterMovement::PlayerHandleEnemyCollision(SDL_Rect thisGuysColliderBox)
{
	currentGameLevel = ZeldaLevel::GetLevel()->GetCurrentGameLevel();

	if (!currentGameLevel->IsThereACollision(thisGuysColliderBox, SG::GameObjectTypes::Enemy))
		return nullptr;
	auto enemy = currentGameLevel->ReturnFirstCollisionGameObject(thisGuysColliderBox, SG::GameObjectTypes::Enemy);
	if (enemy)
		return enemy;
	return nullptr;
}
