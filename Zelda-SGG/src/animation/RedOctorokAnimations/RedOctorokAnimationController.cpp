#include "animation/RedOctorokAnimations/RedOctorokAnimationController.h"
#include "animation/RedOctorokAnimations/RecOctorokWalkingAnimation.h"
#include "graphics/Image.h"


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
}

void RedOctorokAnimationController::Startup()
{
	const auto sdlRect = SDL_Rect{ 0,0, SG::Configuration::TileWidth, SG::Configuration::TileWidth };
	_imageComponent = new SG::ImageComponent(sdlRect, _gameObject);
	_imageComponent->image->ImageIsWholeTexture = false;
	AnimationController::Startup();
}

void RedOctorokAnimationController::Draw(SG::SpriteBatch& spriteBatch)
{
	_imageComponent->UpdateSpriteSheetLocation(_currentAnimation->DrawLocation(_currentFrameOnThisSprite));
	_imageComponent->Draw(spriteBatch);
}
