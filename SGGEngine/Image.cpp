#include "pch.h"
#include  "Image.h"

#include <utility>

#include "Game.h"
#include "Graphics.h"

namespace SG
{
	Graphics* Image::_graphics = nullptr;

	Image::Image(): _imageTexture(nullptr), LocationAndSizeInSpriteSheet(), LocationAndSizeOnRenderer()
	{
	}

	Image::Image(const std::string& filename, const SDL_Rect& spriteSheetLocationAndSize): _imageTexture(nullptr), LocationAndSizeInSpriteSheet()
	{
		_imageTexture = GenerateImage(filename);
		LocationAndSizeInSpriteSheet = spriteSheetLocationAndSize;
	}

	Image::Image(const std::string& filename, Point imageSize)
		:Size(imageSize)
	{
		_imageTexture = GenerateImage(filename);
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

	SDL_Texture* Image::GenerateImage(const std::string& filename)
	{
		if (!_graphics)
			_graphics = Game::GetGraphics();
		return _graphics->LoadTexture(filename);
	}
}
