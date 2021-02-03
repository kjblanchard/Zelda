#include "pch.h"
#include  "Image.h"
#include "Spritesheet.h"
#include "World.h"
#include "Graphics.h"

namespace SG
{
	Graphics* Image::_graphics = nullptr;

	Image::Image(): SpriteSheet(nullptr), LocationAndSizeInSpriteSheet(), LocationAndSizeOnRenderer()
	{
	}

	Image::Image(SpriteSheetEnum spriteSheetToLoad, const SDL_Rect& spriteSheetLocationAndSize): LocationAndSizeInSpriteSheet()
	{
		Size.X = LocationAndSizeOnRenderer.h = spriteSheetLocationAndSize.h;
		Size.Y = LocationAndSizeOnRenderer.w = spriteSheetLocationAndSize.w;
		LocationAndSizeInSpriteSheet = spriteSheetLocationAndSize;
		SpriteSheet = GenerateImage(spriteSheetToLoad);
	}

	Image::Image(SpriteSheetEnum spriteSheetToLoad, Point imageSize) : Size(imageSize), LocationAndSizeInSpriteSheet()
	{
		SpriteSheet = GenerateImage(spriteSheetToLoad);
		ImageIsWholeTexture = true;
		LocationAndSizeOnRenderer.h = Size.X;
		LocationAndSizeOnRenderer.w = Size.Y;
	}

	void Image::UpdateDestRectLocation(Vector3 location)
	{
		Location = location;
		LocationAndSizeOnRenderer.x = Location.X;
		LocationAndSizeOnRenderer.y = Location.Y;
	}

	void Image::UpdateSourceRectLocationInSpriteSheet(const Point& locationOnSpriteSheet)
	{
		LocationAndSizeInSpriteSheet.x = locationOnSpriteSheet.X;
		LocationAndSizeInSpriteSheet.y = locationOnSpriteSheet.Y;
	}

	Spritesheet* Image::GenerateImage(SpriteSheetEnum spriteSheetToLoad)
	{
		if (!_graphics)
			_graphics = World::GetGraphics();
		return _graphics->LoadFromSpriteSheet(spriteSheetToLoad);
	}

}
