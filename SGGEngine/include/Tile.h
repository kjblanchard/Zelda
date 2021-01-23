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
#include <map>
#include <memory>
#include "GameObject.h"
#include "data/Point.h"

namespace SG
{
	class ImageComponent;


	enum class TileTypes
	{
		Default = 5,
		Rock1 = 116,
		Rock2 = 115,
		Rock3 = 114,
		Rock4 = 117,
		Rock5 = 118,
		Ground = 2,
	};

	class SGGENGINE_API Tile : public GameObject
	{
	public:
		Tile();
		Tile(TileTypes tileType, Vector3 location);
		~Tile();

		void Startup() override;
		void Draw(SpriteBatch& spriteBatch) override;

		TileTypes TypeOfTile;
		inline static Point TileSize{ 32,32 };
		inline static std::map<TileTypes, SG::Point> TileTypesToSpriteLocation =
		{
			{TileTypes::Default,Point(5,0)},
			{TileTypes::Rock1,Point(3,14)},
			{TileTypes::Rock2,Point(2,14)},
			{TileTypes::Rock3,Point(1,14)},
			{TileTypes::Rock4,Point(4,14)},
			{TileTypes::Rock5,Point(5,14)},
			{TileTypes::Ground,Point(1,0)}
		};

	private:
		std::unique_ptr<ImageComponent> _imageComponent;

	};
}
