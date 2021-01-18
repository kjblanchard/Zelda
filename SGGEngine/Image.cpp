#include "pch.h"
#include  "Image.h"
#include "Spritesheet.h"
#include "World.h"
#include "Graphics.h"

namespace SG
{
	Graphics* Image::_graphics = nullptr;

	Image::Image(): _imageTexture(nullptr), LocationAndSizeInSpriteSheet(), LocationAndSizeOnRenderer()
	{
	}

	Image::Image(SpriteSheetEnum spriteSheetToLoad, const SDL_Rect& spriteSheetLocationAndSize): _imageTexture(nullptr), LocationAndSizeInSpriteSheet()
	{
		Size.X = LocationAndSizeOnRenderer.h = spriteSheetLocationAndSize.h;
		Size.Y = LocationAndSizeOnRenderer.w = spriteSheetLocationAndSize.w;
		LocationAndSizeInSpriteSheet = spriteSheetLocationAndSize;
		_spriteSheet = GenerateImage(spriteSheetToLoad);
		_imageTexture = _spriteSheet->SpriteSheetTexture;
	}

	Image::Image(SpriteSheetEnum spriteSheetToLoad, Point imageSize) : Size(imageSize)
	{
		_spriteSheet = GenerateImage(spriteSheetToLoad);
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

	SG::Spritesheet* Image::GenerateImage(SpriteSheetEnum spriteSheetToLoad)
	{
		if (!_graphics)
			_graphics = World::GetGraphics();
		return _graphics->LoadFromSpriteSheet(spriteSheetToLoad);
	}

}
