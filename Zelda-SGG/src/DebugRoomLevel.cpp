#include "DebugRoomLevel.h"
#include "Player.h"
#include "Vector3.h"
#include "World.h"

void DebugRoomLevel::Startup()
{
	SG::World::AddToGameObjectList(std::make_unique<Player>(SG::Vector3(32)));
	printf("Startup");

}

void DebugRoomLevel::Update(const double& deltaTime)
{
	auto gameObject = SG::World::RetrieveGameObject(0);
	if (gameObject)
	{
		gameObject->Update(deltaTime);
		//auto player = dynamic_cast<Player*>(gameObject);
		//	if(player)
		//	{
		//		player->Update();
		//	}
		//}

	}
}

void DebugRoomLevel::End()
{
}
