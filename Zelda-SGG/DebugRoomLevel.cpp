#include "DebugRoomLevel.h"
#include "Player.h"
#include "Vector3.h"
#include "World.h"

void DebugRoomLevel::Startup()
{
	SG::World::AddToGameObjectList(std::make_unique<Player>(SG::Vector3(32)));
	printf("Startup");

}

void DebugRoomLevel::Update()
{
	auto go = SG::World::RetrieveGameObject(0);
	if(go)
	{
	auto player = dynamic_cast<Player*>(go);
		if(player)
		{
			player->Update();
		}
	}

}

void DebugRoomLevel::End()
{
}
