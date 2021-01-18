#include "pch.h"
#include "Image.h"
#include  "ImageComponent.h"
#include "SpriteBatch.h"

namespace SG
{


	ImageComponent::ImageComponent(SpriteSheetEnum spriteSheetToLoad, const SDL_Rect& spriteSheetLocationAndSize)
	{
		image = std::make_unique<Image>(spriteSheetToLoad, spriteSheetLocationAndSize);
	}

	ImageComponent::ImageComponent(SpriteSheetEnum spriteSheetToLoad, Point imageSize)
	{
		image = std::make_unique<Image>(spriteSheetToLoad, imageSize);
	}

	ImageComponent::~ImageComponent()
	{
	}


	void ImageComponent::Update(Vector3 location)
	{
		SetLocation(location);
	}

	void ImageComponent::SetLocation(Vector3 location)
	{
		_location = location;
		if (image)
		{
			image->UpdateDestRect(_location);
		}
	}

	void ImageComponent::Draw(SpriteBatch& spritebatch)
	{
		if(image)
			spritebatch.AddToSpriteBatch(image.get());
	}
}
