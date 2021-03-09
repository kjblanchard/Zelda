////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#ifdef SGGENGINE_EXPORTS
#define SGGENGINE_API __declspec(dllexport)
#else
#define SGGENGINE_API __declspec(dllimport)
#endif
#include  "Tile.h"
#include "components/BoxColliderComponent.h"
#include "core/Configuration.h"

namespace SG
{

	/// <summary>
	/// Used when spawning from the tilemap, all of the solid tiles
	/// </summary>
	/// <typeparam name="T">An enum value of the tile type.  The enum value number should match from Tiled</typeparam>
	template <typename T>
	class  SolidTile : public GameObject
	{
	public:
		SolidTile(T tileType, Vector3 location, const Point& locationInSpriteSheet);
		void Startup() override;
		void Update(const double& deltaTime) override;
		void Draw(SpriteBatch& spriteBatch) override;

	private:
		std::unique_ptr<SG::BoxColliderComponent> _boxColliderComponent;
		std::unique_ptr <Tile<T>> _tile;
	};

	template <typename T>
	SolidTile<T>::SolidTile(T tileType, Vector3 location, const Point& locationInSpriteSheet) : GameObject(location)
	{
		_tile = std::make_unique<Tile<T>>(tileType, location, locationInSpriteSheet);
	}

	template <typename T>
	void SolidTile<T>::Startup()
	{
		auto boxColliderBox = SDL_Rect{ 0,0,Configuration::BaseConfigurationSettings.TileWidth,Configuration::BaseConfigurationSettings.TileHeight};

		_boxColliderComponent = std::make_unique<BoxColliderComponent>(this, boxColliderBox);
		_tile->Startup();
		_boxColliderComponent->Startup();
	}

	template <typename T>
	void SolidTile<T>::Update(const double& deltaTime)
	{
	}

	template <typename T>
	void SolidTile<T>::Draw(SpriteBatch& spriteBatch)
	{
		_tile->Draw(spriteBatch);
		_boxColliderComponent->Draw(spriteBatch);
	}
}
