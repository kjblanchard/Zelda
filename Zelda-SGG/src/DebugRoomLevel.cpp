#include "DebugRoomLevel.h"
#include "Link.h"
#include "GameObjectList.h"
#include "Sound.h"
#include "ZeldaTiled.h"

SG::GameObjectList DebugRoomLevel::_levelGameObjectList;

void DebugRoomLevel::Startup()
{
	TileMap.reset(SG::TileMap::GenerateTileMap("overworld.json"));
	ZeldaTiled::CreateTileMapGameObjects(*TileMap, _levelGameObjectList);
    ZeldaTiled::CreateObjectsFromJson(_levelGameObjectList);
	SG::Sound::PlayMusic(SG::MusicToPlay::Overworld);
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

