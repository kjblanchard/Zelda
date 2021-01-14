﻿#include "DebugRoomLevel.h"
#include "Player.h"
#include "Vector3.h"
#include "GameObjectList.h"

void DebugRoomLevel::Startup()
{
	LevelGameObjectList.AddToGameObjectList(std::make_unique<Player>(SG::Vector3(32)));
	printf("Startup");

}

void DebugRoomLevel::Update(const double& deltaTime)
{
	LevelGameObjectList.GameObjectStartup();
	for (auto&& gameObject : SG::GameObjectList::_gameObjectList)
	{
		gameObject->Update(deltaTime);
	}
}

void DebugRoomLevel::Draw(SG::SpriteBatch& spriteBatch)
{
	for (auto&& gameObject : SG::GameObjectList::_gameObjectList)
	{
		gameObject->Draw(spriteBatch);
	}
}

void DebugRoomLevel::End()
{
}
