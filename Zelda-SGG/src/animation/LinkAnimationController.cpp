#include "animation/LinkAnimationController.h"
#include "Image.h"
#include "SpriteBatch.h"
#include "components/ImageComponent.h"


//statics
std::vector<SG::Animation<LinkAnimations>> SG::AnimationController<LinkAnimations>::Animations;



void LinkAnimationController::Startup()
{
	if(!staticsInitialized)
	{
		Animations = {
			{LinkWalkUp() },
			{LinkWalkRight()},
			{LinkWalkDown()},
			{LinkWalkLeft()}
		};
	staticsInitialized = true;
	}

	const auto sdlRect = SDL_Rect{ 0,0,32,32 };
	ImageComponent = new SG::ImageComponent(SG::SpriteSheetEnum::LinkWalking,sdlRect, GameObject);
	ImageComponent->image->ImageIsWholeTexture = false;
}

void LinkAnimationController::Update(const double& deltaTime)
{
	TimeOnCurrentFrame += deltaTime;
	if (TimeOnCurrentFrame >= FrameTime)
	{
		auto desiredFrame = CurrentFrameInAnimation + 1;
		CurrentFrameInAnimation++;
		if (desiredFrame > CurrentAnimation->LocationAndLengthOfAnimation[CurrentFrameOnThisSprite].second)
		{
			desiredFrame = CurrentFrameOnThisSprite + 1;
			if (desiredFrame >= CurrentAnimation->TotalAnimationFrames())
			{
				CurrentFrameOnThisSprite = 0;
				CurrentFrameInAnimation = 0;
			}
			else
			{
				++CurrentFrameOnThisSprite;
				CurrentFrameInAnimation = 0;
			}
		}

	}
	else
	{
		CurrentFrameInAnimation = 0;
	}

	TimeOnCurrentFrame = 0;
}

void LinkAnimationController::Draw(SG::SpriteBatch& spriteBatch)
{
	//auto spritesheetpoint = CurrentAnimation->LocationAndLengthOfAnimation[CurrentFrameOnThisSprite].first;
	//ImageComponent->image->LocationAndSizeInSpriteSheet.x = spritesheetpoint.X *= 32;
	//ImageComponent->image->LocationAndSizeInSpriteSheet.y = spritesheetpoint.Y *=32;
	ImageComponent->image->UpdateSourceRectLocationInSpriteSheet(CurrentAnimation->DrawLocation(CurrentFrameOnThisSprite));
	ImageComponent->Draw(spriteBatch);
}
