////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "LinkAnimations.h"
#include "graphics/Spritesheet.h"
#include "animation/Animation.h"
#include "data/Point.h"

class LinkWalkUp : public SG::Animation<LinkAnimations>
{
public:

	LinkWalkUp() : Animation<LinkAnimations>()
	{
		AnimationEnumType = LinkAnimations::WalkUp;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking);
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

	LinkWalkRight() : Animation<LinkAnimations>()
	{
		AnimationEnumType = LinkAnimations::WalkRight;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking);
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

	LinkWalkDown() : Animation<LinkAnimations>()
	{
		AnimationEnumType = LinkAnimations::WalkDown;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking);
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

	LinkWalkLeft() : Animation<LinkAnimations>()
	{
		AnimationEnumType = LinkAnimations::WalkLeft;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalking);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,2), 7},
			{SG::Point(1,2), 7 }
		};
	}
};
