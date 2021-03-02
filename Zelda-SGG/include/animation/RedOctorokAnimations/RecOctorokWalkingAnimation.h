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
