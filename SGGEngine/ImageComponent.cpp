#include "pch.h"
#include "Image.h"
#include  "ImageComponent.h"
#include "SpriteBatch.h"

namespace SG
{
	ImageComponent::ImageComponent(const std::string& filename, const SDL_Rect& spriteSheetLocationAndSize)
	{
		image = std::make_unique<Image>(filename, spriteSheetLocationAndSize);
	}

	ImageComponent::ImageComponent(const std::string& filename, Point imageSize)
	{
		image = std::make_unique<Image>(filename, imageSize);
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
