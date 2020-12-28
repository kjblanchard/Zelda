#include "pch.h"


#include  "ImageComponent.h"

namespace SG
{
	ImageComponent::ImageComponent(GameObject* owner): _owner(owner)
	{
		_componentType = ComponentTypes::Image;
	}

	ImageComponent::~ImageComponent()
	{
		SDL_DestroyTexture(Texture);
	}
}
