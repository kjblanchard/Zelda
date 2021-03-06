﻿#include "levels/DebugRoomLevel.h"
#include "characters/Link.h"
#include "core/GameObjectList.h"
#include "core/Sound.h"
#include "ZeldaTiled.h"


void DebugRoomLevel::Startup()
{
	TileMap.reset(SG::TileMap::GenerateTileMap("overworld.json"));
	ZeldaTiled::CreateTileMapGameObjects(*TileMap, *TileLayerList);
	ZeldaTiled::CreateSolidTileMapGameObjects(*TileMap,* SolidLayerList);
    ZeldaTiled::CreatePlayersFromJson(*PlayerLayerList);
	ZeldaTiled::CreateEnemiesFromJson(*TileMap, *EnemiesLayerList);
	SG::Sound::PlayMusic(SG::MusicToPlay::Overworld);
}

void DebugRoomLevel::Update(const double& deltaTime)
{
	TileLayerList->Update(deltaTime);
	SolidLayerList->Update(deltaTime);
	EnemiesLayerList->Update(deltaTime);
	PlayerLayerList->Update(deltaTime);
}

void DebugRoomLevel::Draw(SG::SpriteBatch& spriteBatch)
{
	TileLayerList->Draw(spriteBatch);
	SolidLayerList->Draw(spriteBatch);
	EnemiesLayerList->Draw(spriteBatch);
	PlayerLayerList->Draw(spriteBatch);
}

void DebugRoomLevel::End()
{
}

