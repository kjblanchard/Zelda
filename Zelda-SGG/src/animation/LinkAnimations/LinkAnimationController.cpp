#include "animation/LinkAnimations/LinkAnimationController.h"
#include "Image.h"
#include "SpriteBatch.h"
#include "Statics.h"
#include "animation/LinkAnimations/LinkAttackingAnimation.h"
#include "animation/LinkAnimations/LinkWalkingAnimation.h"
#include "components/ImageComponent.h"


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

		};
		staticsInitialized = true;
	}
}

void LinkAnimationController::Startup()
{

	const auto sdlRect = SDL_Rect{ 0,0,Statics::TileSize.X, Statics::TileSize.Y };
	//_imageComponent = new SG::ImageComponent(SG::SpriteSheetEnum::LinkWalking,sdlRect, _gameObject);
	_imageComponent = new SG::ImageComponent( sdlRect, _gameObject);

	_imageComponent->image->ImageIsWholeTexture = false;
}

void LinkAnimationController::Draw(SG::SpriteBatch& spriteBatch)
{
	_imageComponent->UpdateSpriteSheetLocation(_currentAnimation->DrawLocation(_currentFrameOnThisSprite));
	_imageComponent->Draw(spriteBatch);
}
