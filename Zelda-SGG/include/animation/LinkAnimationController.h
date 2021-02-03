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

class LinkWalkUp : public SG::Animation<LinkAnimations>
{
public:

	LinkWalkUp()
	{
		AnimationEnumType = LinkAnimations::WalkUp;
		SpriteSheet = SG::World::GetGraphics()->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,0), 7},
			{SG::Point(1,0), 7 }
		};
	}

};
class LinkWalkRight : public SG::Animation<LinkAnimations>
{
public:

	LinkWalkRight()
	{
		AnimationEnumType = LinkAnimations::WalkRight;
		SpriteSheet = SG::World::GetGraphics()->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,3), 7},
			{SG::Point(1,3), 7 }
		};
	}
};
class LinkWalkDown : public SG::Animation<LinkAnimations>
{
public:

	LinkWalkDown()
	{
		AnimationEnumType = LinkAnimations::WalkDown;
		SpriteSheet = SG::World::GetGraphics()->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,1), 7},
			{SG::Point(1,1), 7 }
		};
	}
};
class LinkWalkLeft :public  SG::Animation<LinkAnimations>
{
public:

	LinkWalkLeft()
	{
		AnimationEnumType = LinkAnimations::WalkLeft;
		SpriteSheet = SG::World::GetGraphics()->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,2), 7},
			{SG::Point(1,2), 7 }
		};
	}
};



class LinkAnimationController : public SG::AnimationController<LinkAnimations>
{
public:
	LinkAnimationController() = default ;
	LinkAnimationController(SG::GameObject* gameObject) : AnimationController(gameObject) {}

	void Startup() override;
	void Update(const double& deltaTime) override;
	void Draw(SG::SpriteBatch& spriteBatch) override;


};
