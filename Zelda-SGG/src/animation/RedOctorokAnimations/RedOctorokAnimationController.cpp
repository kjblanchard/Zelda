#include "animation/RedOctorokAnimations/RedOctorokAnimationController.h"
#include "animation/RedOctorokAnimations/RecOctorokWalkingAnimation.h"
#include "graphics/Image.h"

#include "characters/RedOctorok.h"


//statics
std::vector<SG::Animation<RedOctorokAnimations>> SG::AnimationController<RedOctorokAnimations>::Animations;

RedOctorokAnimationController::RedOctorokAnimationController(SG::GameObject* owner) : AnimationController(owner)
{
	if (!staticsInitialized)
	{
		Animations = {
			{RedOctorokWalkUp() },
			{RedOctorokWalkDown() },
			{RedOctorokWalkLeft() },
			{RedOctorokWalkRight() },

		};
		staticsInitialized = true;
	}
	_redOcto = dynamic_cast<RedOctorok*>(owner);
}

void RedOctorokAnimationController::Startup()
{
	const auto sdlRect = SDL_Rect{ 0,0, SG::Configuration::BaseConfigurationSettings.TileWidth, SG::Configuration::BaseConfigurationSettings.TileWidth };
	_imageComponent = new SG::ImageComponent(sdlRect, _gameObject);
	_imageComponent->image->ImageIsWholeTexture = false;
	AnimationController::Startup();
}

void RedOctorokAnimationController::Update(const double& deltaTime)
{
	AnimationController::Update(deltaTime);

	if (_redOcto->_isInvincible)
	{
		currentInvincibilityFrame++;
		if (currentInvincibilityFrame > maxInvFrame)
			currentInvincibilityFrame = 0;
		UpdateSpriteLocation(_gameObject->Location());
	}
}

void RedOctorokAnimationController::Draw(SG::SpriteBatch& spriteBatch)
{
	if(_redOcto->_isInvincible)
	{
		auto currentFrameInInvincibility = CalculateCurrentFrameInInvincibility();
		auto coolBoi = _currentAnimation->DrawLocation(_currentFrameOnThisSprite);
		coolBoi.Y += currentFrameInInvincibility * invFrameOffset;
		_imageComponent->UpdateSpriteSheetLocation(coolBoi);
		_imageComponent->Draw(spriteBatch);
	}
	else
	{

	_imageComponent->UpdateSpriteSheetLocation(_currentAnimation->DrawLocation(_currentFrameOnThisSprite));
	_imageComponent->Draw(spriteBatch);

	}
}
