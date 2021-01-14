#include "DebugRoomLevel.h"
#include "Player.h"
#include "Vector3.h"
#include "GameObjectList.h"

void DebugRoomLevel::Startup()
{
	_levelGameObjectList.AddToGameObjectList(new Player(SG::Vector3(32)));
}

void DebugRoomLevel::Update(const double& deltaTime)
{
	_levelGameObjectList.Update(deltaTime);
}

void DebugRoomLevel::Draw(SG::SpriteBatch& spriteBatch)
{
	_levelGameObjectList.Draw(spriteBatch);
}

void DebugRoomLevel::End()
{
	_levelGameObjectList.Reset();
}
