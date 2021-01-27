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
#include <memory>

#include "GameObject.h"
#include "components/ImageComponent.h"
#include "data/Point.h"

namespace SG
{

	template <typename T>
	class Tile : public GameObject
	{
	public:
		Tile(T tileType, Vector3 location, const Point& locationInSpriteSheet);
		~Tile();

		void Startup() override;
		void Draw(SpriteBatch& spriteBatch) override;

		T TypeOfTile;
		Point LocationInSpriteSheet;
		inline static Point TileSize{ 32,32 };

	private:
		std::unique_ptr<ImageComponent> _imageComponent;

	};

	template <typename T>
	Tile<T>::Tile(T tileType, Vector3 location, const Point& locationInSpriteSheet) : TypeOfTile(tileType), LocationInSpriteSheet(locationInSpriteSheet),_imageComponent(nullptr)
	{
		_location = location;
	}

	template <typename T>
	Tile<T>::~Tile()
	{
	}

	template <typename T>
	void Tile<T>::Startup()
	{
		auto spritesheetrect = SDL_Rect{ LocationInSpriteSheet.X * TileSize.X,LocationInSpriteSheet.Y * TileSize.Y ,TileSize.X,TileSize.Y };
		_imageComponent = std::make_unique<SG::ImageComponent>(SpriteSheetEnum::TileSet, spritesheetrect, this);
		_imageComponent->SetLocation(Location());
	}

	template <typename T>
	void Tile<T>::Draw(SpriteBatch& spriteBatch)
	{
		_imageComponent->Draw(spriteBatch);
	}

}
