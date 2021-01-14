#include "DebugRoomLevel.h"
#include "Player.h"
#include "Vector3.h"
#include "GameObjectList.h"
#include "Tile.h"

void DebugRoomLevel::Startup()
{
	_levelGameObjectList.AddToGameObjectList(new SG::Tile(SG::Vector3(0)));
	_levelGameObjectList.AddToGameObjectList(new SG::Tile(SG::Vector3(64)));
	_levelGameObjectList.AddToGameObjectList(new SG::Tile(SG::Vector3(128)));

	_levelGameObjectList.AddToGameObjectList(new Player(SG::Vector3(32.0)));

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
