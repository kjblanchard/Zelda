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
		UpdateSpriteDestinationInWorld(location);
	}

	void ImageComponent::Draw(SpriteBatch& spritebatch) const
	{
		if(image)
			spritebatch.AddToSpriteBatch(image.get());
	}



	void ImageComponent::UpdateSpriteSheetLocation(const Point& locationInSpriteSheet) const
	{
		if(image)
		{
			image->LocationAndSizeInSpriteSheet.x = locationInSpriteSheet.X;
			image->LocationAndSizeInSpriteSheet.y = locationInSpriteSheet.Y;
		}
	}

	void ImageComponent::UpdateSpriteDestinationInWorld(const Vector3& worldLocation)
	{
		if(image)
		{
			image->Location = worldLocation;
			image->LocationAndSizeOnRenderer.x = worldLocation.X;
			image->LocationAndSizeOnRenderer.y = worldLocation.Y;
		}
	}
}
