#include "pch.h"

#include "animation/Animation.h"

namespace SG
{
	Point Animation::Update(const double& deltaTime)
	{
		CurrentAnimationTime += deltaTime;
		auto animationTime = LocationAndLengthOfAnimation[CurrentFrameInAnimation].second;
		if( CurrentAnimationTime >= animationTime)
		{
			if(CurrentFrameInAnimation + 1 >= LocationAndLengthOfAnimation.size())
			{
				CurrentFrameInAnimation = 0;
			}
			else
				++CurrentFrameInAnimation;
			CurrentAnimationTime = 0;
		}
		return LocationAndLengthOfAnimation[CurrentFrameInAnimation].first;
	}
}
