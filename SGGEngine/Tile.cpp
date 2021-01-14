#include "pch.h"
#include  "Tile.h"

#include "ImageComponent.h"

namespace SG
{
	Tile::Tile() : GameObject(),_imageComponent(nullptr)
	{
	}

	Tile::Tile(Vector3 location) : Tile()
	{
		_location = location;
	}

	Tile::~Tile()
	{
	}

	void Tile::Startup()
	{
		auto spritesheetrect = SDL_Rect{ 32,0,32,32 };
		_imageComponent = std::make_unique<SG::ImageComponent>("tileset.png",spritesheetrect );
		_imageComponent->SetLocation(Location());
	}

	void Tile::Draw(SpriteBatch& spriteBatch)
	{
		_imageComponent->Draw(spriteBatch);
	}


}
