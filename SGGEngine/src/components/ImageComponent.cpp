#include "pch.h"
#include "Image.h"
#include "components/ImageComponent.h"

#include "SpriteBatch.h"

namespace SG
{
	ImageComponent::ImageComponent(SpriteSheetEnum spriteSheetToLoad, const SDL_Rect& spriteSheetLocationAndSize,
		GameObject* gameObject) : Component(gameObject,SGComponentTypes::Image)
	{
		image = std::make_unique<Image>(spriteSheetToLoad, spriteSheetLocationAndSize);
	}

	ImageComponent::ImageComponent(SpriteSheetEnum spriteSheetToLoad, Point imageSize, GameObject* gameObject) : Component(gameObject,SGComponentTypes::Image)
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

	void ImageComponent::Draw(SpriteBatch& spritebatch) const
	{
		if(image)
			spritebatch.AddToSpriteBatch(image.get());
	}

	void ImageComponent::SetLocation(Vector3 location)
	{
		_location = location;
		if (image)
		{
			image->UpdateDestRectLocation(_location);
		}
	}
}
