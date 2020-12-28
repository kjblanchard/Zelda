#include "pch.h"


#include  "SpriteBatch.h"

namespace SG
{
	void SpriteBatch::AddToSpriteBatch(Image* imageToDraw)
	{
		_gameTextures.push_back(imageToDraw);

	}
}
