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

	void ImageComponent::Draw(SpriteBatch& spritebatch)
	{
		spritebatch.AddToSpriteBatch(image.get());
	}
}
