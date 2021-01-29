#include "pch.h"
#include "Image.h"

#include  "AnimationComponent.h"

#include "GameObject.h"

namespace SG
{
	AnimationComponent::AnimationComponent(GameObject* gameObject): Component(gameObject,SGComponentTypes::Animation), _imageComponent(nullptr)
	{
	}

	void AnimationComponent::Startup()
	{
		_imageComponent = new ImageComponent(SG::SpriteSheetEnum::LinkWalking, SG::Point{ 32,32 },_gameObject);
	}

	void AnimationComponent::Update(const double& deltaTime)
	{
		_currentAnimation.Update(deltaTime);
		_imageComponent->Update(_gameObject->Location());
	}

	void AnimationComponent::Draw(SpriteBatch& spriteBatch)
	{
		auto spritesheetpoint = _currentAnimation.LocationAndLengthOfAnimation[_currentAnimation.CurrentFrameInAnimation].first;
		spritesheetpoint.X *= 32;
		spritesheetpoint.Y *= 32;
		_imageComponent->image->LocationAndSizeInSpriteSheet.h = 32;
		_imageComponent->image->LocationAndSizeInSpriteSheet.w = 32;
		_imageComponent->image->LocationAndSizeInSpriteSheet.x = spritesheetpoint.X;
		_imageComponent->image->LocationAndSizeInSpriteSheet.y = spritesheetpoint.Y;
		_imageComponent->image->ImageIsWholeTexture = false;
		_imageComponent->Draw(spriteBatch);
	}
}
