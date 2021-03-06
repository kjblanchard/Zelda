﻿////////////////////////////////////////////////////////////
//
// Super Goon Games - Multiplayer Zelda
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#include "LinkAnimations.h"
#include "animation/Animation.h"

class LinkAttackUp : public SG::Animation<LinkAnimations>
{
public:

	LinkAttackUp() : Animation<LinkAnimations>()
	{
		AnimationEnumType = LinkAnimations::AttackUp;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkAttacking);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,0), 7},
			{SG::Point(0,0), 7},

		};
	}
};
class LinkAttackDown : public SG::Animation<LinkAnimations>
{
public:

	LinkAttackDown() : Animation<LinkAnimations>()
	{
		AnimationEnumType = LinkAnimations::AttackDown;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkAttacking);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,1), 7},
			{SG::Point(0,1), 7},

		};
	}
};
class LinkAttackLeft : public SG::Animation<LinkAnimations>
{
public:

	LinkAttackLeft() : Animation<LinkAnimations>()
	{
		AnimationEnumType = LinkAnimations::AttackLeft;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkAttacking);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,2), 7},
			{SG::Point(0,2), 7},

		};
	}
};
class LinkAttackRight : public SG::Animation<LinkAnimations>
{
public:

	LinkAttackRight() : Animation<LinkAnimations>()
	{
		AnimationEnumType = LinkAnimations::AttackRight;
		SpriteSheet = _graphics->LoadFromSpriteSheet(SG::SpriteSheetEnum::LinkAttacking);
		LocationAndLengthOfAnimation =
		{
			{SG::Point(0,3), 7},
			{SG::Point(0,3), 7},

		};
	}
};
