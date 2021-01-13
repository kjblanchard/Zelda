#include "DebugRoomLevel.h"
#include "Player.h"
#include "Vector3.h"
#include "World.h"
#include "GameObjectList.h"

void DebugRoomLevel::Startup()
{
	SG::GameObjectList::AddToGameObjectList(std::make_unique<Player>(SG::Vector3(32)));
	printf("Startup");

}

void DebugRoomLevel::Update(const double& deltaTime)
{
	auto gameObject = SG::GameObjectList::RetrieveGameObject(0);
	if (gameObject)
	{
		gameObject->Update(deltaTime);

	}
}

void DebugRoomLevel::End()
{
}
