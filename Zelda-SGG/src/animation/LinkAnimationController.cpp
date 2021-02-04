#include "animation/LinkAnimationController.h"
#include "Image.h"
#include "SpriteBatch.h"
#include "Statics.h"
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
			{LinkWalkLeft()}
		};
		staticsInitialized = true;
	}
}

void LinkAnimationController::Startup()
{

	const auto sdlRect = SDL_Rect{ 0,0,Statics::TileSize.X, Statics::TileSize.Y };
	ImageComponent = new SG::ImageComponent(SG::SpriteSheetEnum::LinkWalking,sdlRect, GameObject);
	ImageComponent->image->ImageIsWholeTexture = false;
}

void LinkAnimationController::Draw(SG::SpriteBatch& spriteBatch)
{
	ImageComponent->UpdateSpriteSheetLocation(CurrentAnimation->DrawLocation(CurrentFrameOnThisSprite));
	ImageComponent->Draw(spriteBatch);
}
