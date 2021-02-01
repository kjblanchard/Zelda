#include "animation/LinkAnimationController.h"

#include "SpriteBatch.h"
#include "components/ImageComponent.h"
#include "Image.h"


std::vector<SG::Animation> SG::AnimationController::Animations;
//std::vector < std::pair<SG::Point, int>> SG::Animation::LocationAndLengthOfAnimation;



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

		if(desiredFrame < CurrentTotalAnimationFrames)
		{
			CurrentFrameInAnimation++;
			if(desiredFrame > CurrentAnimation.LocationAndLengthOfAnimation[CurrentFrameOnThisSprite].second)
			{
			desiredFrame = CurrentFrameOnThisSprite + 1;
				if (desiredFrame >= CurrentAnimation.LocationAndLengthOfAnimation.size())
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
}

void LinkAnimationController::Draw(SG::SpriteBatch& spriteBatch)
{
	auto spritesheetpoint = CurrentAnimation.LocationAndLengthOfAnimation[CurrentFrameOnThisSprite].first;
	spritesheetpoint.X *= 32;
	spritesheetpoint.Y *= 32;
	ImageComponent->image->LocationAndSizeInSpriteSheet.x = spritesheetpoint.X;
	ImageComponent->image->LocationAndSizeInSpriteSheet.y = spritesheetpoint.Y;
	ImageComponent->Draw(spriteBatch);
}

void LinkAnimationController::ChangeAnimation(int animationEnum)
{
	for (auto animation : Animations)
	{
		if(animation.AnimationEnumType == animationEnum)
		{
			CurrentAnimation = animation;
			int totalAnimationFrames = 0;
			for (auto locationAndLengthOfAnimation : animation.LocationAndLengthOfAnimation)
			{
				totalAnimationFrames += locationAndLengthOfAnimation.second;
			}
			CurrentTotalAnimationFrames = totalAnimationFrames;
		}
	}
}
