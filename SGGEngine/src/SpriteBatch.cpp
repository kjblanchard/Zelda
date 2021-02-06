#include "pch.h"


#include  "SpriteBatch.h"

namespace SG
{
	void SpriteBatch::AddToSpriteBatch(Image* imageToDraw)
	{
		_gameTextures.push_back(imageToDraw);

	}

	void SpriteBatch::AddToSpriteBatch(SDL_Rect* debugBoxToDraw)
	{
		_debugBoxes.push_back(debugBoxToDraw);
	}
}
