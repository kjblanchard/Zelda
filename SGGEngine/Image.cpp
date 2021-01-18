#include "pch.h"
#include  "Image.h"

#include <utility>
#include "Spritesheet.h"
#include "World.h"
#include "Graphics.h"

namespace SG
{
	Graphics* Image::_graphics = nullptr;

	Image::Image(): _imageTexture(nullptr), LocationAndSizeInSpriteSheet(), LocationAndSizeOnRenderer()
	{
	}

	Image::Image(const std::string& filename, const SDL_Rect& spriteSheetLocationAndSize): _imageTexture(nullptr), LocationAndSizeInSpriteSheet()
	{
		Size.X = LocationAndSizeOnRenderer.h = spriteSheetLocationAndSize.h;
		Size.Y = LocationAndSizeOnRenderer.w = spriteSheetLocationAndSize.w;
		LocationAndSizeInSpriteSheet = spriteSheetLocationAndSize;
		_spriteSheet = GenerateImage(filename);
		_imageTexture = _spriteSheet->SpriteSheetTexture;

	}

	Image::Image(const std::string& filename, Point imageSize)
		:Size(imageSize)
	{
		_spriteSheet = GenerateImage(filename);
		_imageTexture = _spriteSheet->SpriteSheetTexture;
		isWholeTexture = true;
		LocationAndSizeOnRenderer.h = Size.X;
		LocationAndSizeOnRenderer.w = Size.Y;

	}


	Image::~Image()
	{
		SDL_DestroyTexture(_imageTexture);
	}

	void Image::UpdateDestRect(Vector3 location)
	{
		Location = location;
		LocationAndSizeOnRenderer.x = Location.X;
		LocationAndSizeOnRenderer.y = Location.Y;
	}

	Spritesheet* Image::GenerateImage(const std::string& filename)
	{
		if (!_graphics)
			_graphics = World::GetGraphics();
		return _graphics->LoadFromSpriteSheet(SpriteSheetEnum::TileSet);
	}
}
