////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "animation/AnimationController.h"
#include "animation/Animation.h"

enum class LinkAnimations
{
	Default = 0,
	Idle = 1,
	WalkUp = 2,
	WalkRight = 3,
	WalkDown = 4,
	WalkLeft = 5
};

class LinkWalkUp : public SG::Animation
{
public:
	LinkWalkUp()
	{
		AnimationEnumType = (int)LinkAnimations::WalkUp;
		SpriteSheet = SG::World::GetGraphics()->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,0), 10},
			{SG::Point(1,0), 10 }
		};
	}
};
class LinkWalkRight : public SG::Animation
{
public:

	LinkWalkRight()
	{
		AnimationEnumType = (int)LinkAnimations::WalkRight;
		SpriteSheet = SG::World::GetGraphics()->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,3), 10},
			{SG::Point(1,3), 10 }
		};
	}
};
class LinkWalkDown : public SG::Animation
{
public:

	LinkWalkDown()
	{
		AnimationEnumType = (int)LinkAnimations::WalkDown;
		SpriteSheet = SG::World::GetGraphics()->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,1), 10},
			{SG::Point(1,1), 10 }
		};
	}
};
class LinkWalkLeft :public  SG::Animation
{
public:

	LinkWalkLeft()
	{
		AnimationEnumType = (int)LinkAnimations::WalkLeft;
		SpriteSheet = SG::World::GetGraphics()->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,2), 10},
			{SG::Point(1,2), 10 }
		};
	}
};



class LinkAnimationController : public SG::AnimationController
{
public:
	LinkAnimationController() = default;
	LinkAnimationController(SG::GameObject* gameObject) : AnimationController(gameObject) {}

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;
	void ChangeAnimation(int animationEnum) override;


};
