#include "DebugRoomLevel.h"
#include "Link.h"
#include "GameObjectList.h"
#include "Sound.h"
#include "ZeldaTiled.h"

void DebugRoomLevel::Startup()
{
	TileMap.reset(SG::TileMap::GenerateTileMap("overworld.json"));
	ZeldaTiled::CreateTileMapGameObjects(*TileMap, _levelGameObjectList);
	_levelGameObjectList.AddToGameObjectList( ZeldaTiled::CreatePlayerFromJson());
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

