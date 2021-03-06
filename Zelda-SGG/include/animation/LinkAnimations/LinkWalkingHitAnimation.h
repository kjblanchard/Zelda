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

class LinkWalkHitUp : public SG::Animation<LinkAnimations>
{
public:

	LinkWalkHitUp() : Animation<LinkAnimations>()
	{
		AnimationEnumType = LinkAnimations::WalkHitUp;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalkingHit);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,0), 3},
			{SG::Point(0,4), 3 }
		};
	}

};

class LinkWalkHitDown : public SG::Animation<LinkAnimations>
{
public:

	LinkWalkHitDown() : Animation<LinkAnimations>()
	{
		AnimationEnumType = LinkAnimations::WalkHitDown;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalkingHit);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,1), 3},
			{SG::Point(0,5), 3 }
		};
	}

};

class LinkWalkHitLeft : public SG::Animation<LinkAnimations>
{
public:

	LinkWalkHitLeft() : Animation<LinkAnimations>()
	{
		AnimationEnumType = LinkAnimations::WalkHitLeft;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalkingHit);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,2), 3},
			{SG::Point(0,6), 3 }
		};
	}

};
class LinkWalkHitRight : public SG::Animation<LinkAnimations>
{
public:

	LinkWalkHitRight() : Animation<LinkAnimations>()
	{
		AnimationEnumType = LinkAnimations::WalkHitRight;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkWalkingHit);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,3), 3},
			{SG::Point(0,7), 3 }
		};
	}

};
