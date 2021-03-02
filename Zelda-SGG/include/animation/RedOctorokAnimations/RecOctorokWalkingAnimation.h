////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "RedOctorokAnimations.h"
#include "animation/Animation.h"
#include "graphics/Image.h"

class RedOctorokWalkUp : public SG::Animation<RedOctorokAnimations>
{
public:

	RedOctorokWalkUp() : Animation<RedOctorokAnimations>()
	{
		AnimationEnumType = RedOctorokAnimations::WalkUp;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::RedOctorok);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,0), 7},
			{SG::Point(1,0), 7 }
		};
	}
};
class RedOctorokWalkDown : public SG::Animation<RedOctorokAnimations>
{
public:

	RedOctorokWalkDown() : Animation<RedOctorokAnimations>()
	{
		AnimationEnumType = RedOctorokAnimations::WalkDown;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::RedOctorok);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,0), 7},
			{SG::Point(1,0), 7 }
		};
	}
};
class RedOctorokWalkLeft : public SG::Animation<RedOctorokAnimations>
{
public:

	RedOctorokWalkLeft() : Animation<RedOctorokAnimations>()
	{
		AnimationEnumType = RedOctorokAnimations::WalkLeft;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::RedOctorok);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,0), 7},
			{SG::Point(1,0), 7 }
		};
	}
};
class RedOctorokWalkRight : public SG::Animation<RedOctorokAnimations>
{
public:

	RedOctorokWalkRight() : Animation<RedOctorokAnimations>()
	{
		AnimationEnumType = RedOctorokAnimations::WalkRight;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::RedOctorok);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,0), 7},
			{SG::Point(1,0), 7 }
		};
	}
};
