#include "animation/LinkAnimations/LinkAnimationController.h"
#include "graphics/Image.h"
#include "graphics/SpriteBatch.h"
#include "animation/LinkAnimations/LinkAttackingAnimation.h"
#include "animation/LinkAnimations/LinkWalkingAnimation.h"
#include "animation/LinkAnimations/LinkWalkingHitAnimation.h"
#include "components/ImageComponent.h"
#include "core/Configuration.h"


//statics
std::vector<SG::Animation<LinkAnimations>> SG::AnimationController<LinkAnimations>::Animations;


LinkAnimationController::LinkAnimationController(SG::GameObject* gameObject) : AnimationController(gameObject)
{
	if (!staticsInitialized)
	{
		Animations = {
			{LinkWalkUp() },
			{LinkWalkRight()},
			{LinkWalkDown()},
			{LinkWalkLeft()},
			{LinkAttackUp() },
			{LinkAttackRight()},
			{LinkAttackDown()},
			{LinkAttackLeft()},
			{LinkWalkHitUp()},
			{LinkWalkHitDown()},
			{LinkWalkHitLeft()},
			{LinkWalkHitRight()}

		};
		staticsInitialized = true;
	}
}

void LinkAnimationController::Startup()
{
	const auto sdlRect = SDL_Rect{ 0,0, SG::Configuration::TileWidth, SG::Configuration::TileWidth};
	_imageComponent = new SG::ImageComponent( sdlRect, _gameObject);

	_imageComponent->image->ImageIsWholeTexture = false;
	AnimationController::Startup();
}

void LinkAnimationController::Draw(SG::SpriteBatch& spriteBatch)
{
	_imageComponent->UpdateSpriteSheetLocation(_currentAnimation->DrawLocation(_currentFrameOnThisSprite));
	_imageComponent->Draw(spriteBatch);
}
