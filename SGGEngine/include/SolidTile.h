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

namespace SG
{

	template <typename T>
	class  SolidTile : public GameObject
	{
	public:
		SolidTile(T tileType, Vector3 location, const Point& locationInSpriteSheet);
		void Startup() override;
		void Update(const double& deltaTime) override;
		void Draw(SpriteBatch& spriteBatch) override;

		std::unique_ptr<SG::BoxColliderComponent> _boxColliderComponent;

		Tile<T>* tile;
	};

	template <typename T>
	SolidTile<T>::SolidTile(T tileType, Vector3 location, const Point& locationInSpriteSheet) : GameObject(location)
	{
		tile = new Tile<T>(tileType, location, locationInSpriteSheet);
	}

	template <typename T>
	void SolidTile<T>::Startup()
	{
		_boxColliderComponent = std::make_unique<BoxColliderComponent>(this);
		tile->Startup();
		_boxColliderComponent->Startup();
		_boxColliderComponent->ColliderBox.x = tile->Location().X;
		_boxColliderComponent->ColliderBox.y = tile->Location().Y;
	}

	template <typename T>
	void SolidTile<T>::Update(const double& deltaTime)
	{
	}

	template <typename T>
	void SolidTile<T>::Draw(SpriteBatch& spriteBatch)
	{
		tile->Draw(spriteBatch);
		_boxColliderComponent->Draw(spriteBatch);
	}
}
