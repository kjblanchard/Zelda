#include "animation/LinkAnimationController.h"

#include "SpriteBatch.h"
#include "components/ImageComponent.h"
#include "Image.h"


std::vector<SG::Animation<LinkAnimations>> SG::AnimationController<LinkAnimations>::Animations;
std::vector < std::pair<SG::Point, int>> SG::Animation<LinkAnimations>::LocationAndLengthOfAnimation;

void LinkAnimationController::Startup()
{
	if(!staticsInitialized)
	{

	Animations = {
	SG::Animation<LinkAnimations>
	{
		LinkAnimations::Idle,
		SG::World::GetGraphics()->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking)
	},
	SG::Animation<LinkAnimations>{
					LinkAnimations::WalkUp,
		SG::World::GetGraphics()->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking)
	},
	SG::Animation<LinkAnimations>{
								LinkAnimations::WalkRight,
		SG::World::GetGraphics()->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking)
	},
	SG::Animation<LinkAnimations>{
			LinkAnimations::WalkDown,
		SG::World::GetGraphics()->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking)
	},
	SG::Animation<LinkAnimations>{
						LinkAnimations::WalkLeft,
		SG::World::GetGraphics()->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking)
	}

	};
	Animations[1].LocationAndLengthOfAnimation =
	{
		{SG::Point(0,0), 10},
		{SG::Point(1,0), 10 }
	};
	Animations[2].LocationAndLengthOfAnimation =
	{
		{SG::Point(0,3), 10},
		{SG::Point(1,3), 10 }
	};
	Animations[3].LocationAndLengthOfAnimation =
	{
		{SG::Point(0,1), 10},
		{SG::Point(1,1), 10 }
	};
	Animations[4].LocationAndLengthOfAnimation =
	{
		{SG::Point(0,2), 10},
		{SG::Point(1,2), 10 }
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
		auto desiredFrame = CurrentFrame + 1;
		if (desiredFrame >= CurrentAnimation.LocationAndLengthOfAnimation.size()) {
			CurrentFrame = 0;
		}
		else
		{
			++CurrentFrame;
		}
		TimeOnCurrentFrame = 0;
	}
}

void LinkAnimationController::Draw(SG::SpriteBatch& spriteBatch)
{
	auto spritesheetpoint = CurrentAnimation.LocationAndLengthOfAnimation[CurrentFrame].first;
	spritesheetpoint.X *= 32;
	spritesheetpoint.Y *= 32;
	ImageComponent->image->LocationAndSizeInSpriteSheet.x = spritesheetpoint.X;
	ImageComponent->image->LocationAndSizeInSpriteSheet.y = spritesheetpoint.Y;
	ImageComponent->Draw(spriteBatch);
}

void LinkAnimationController::ChangeAnimation(LinkAnimations animationEnum)
{
}
