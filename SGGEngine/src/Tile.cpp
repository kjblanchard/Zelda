#include "pch.h"
#include  "Tile.h"

#include <SDL_rect.h>
#include "components/ImageComponent.h"
#include "Spritesheet.h"


namespace SG
{

	Tile::Tile() : GameObject(),_imageComponent(nullptr)
	{
	}

	Tile::Tile(TileTypes tileType, Vector3 location) : Tile()
	{
		_location = location;
		TypeOfTile = tileType;
	}

	Tile::~Tile()
	{
	}

	void Tile::Startup()
	{
		auto spritesheetLocation = TileTypesToSpriteLocation.at(TypeOfTile);
		auto spritesheetrect = SDL_Rect{ spritesheetLocation.X * TileSize.X,spritesheetLocation.Y * TileSize.Y ,TileSize.X,TileSize.Y };
		_imageComponent = std::make_unique<SG::ImageComponent>(SpriteSheetEnum::TileSet,spritesheetrect );
		_imageComponent->SetLocation(Location());
	}

	void Tile::Draw(SpriteBatch& spriteBatch)
	{
		_imageComponent->Draw(spriteBatch);
	}


}
