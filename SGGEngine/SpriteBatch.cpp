#include "pch.h"


#include  "SpriteBatch.h"

namespace SG
{
	void SpriteBatch::AddToSpriteBatch(SDL_Texture* textureToAdd)
	{
		_gameTextures.push_back(textureToAdd);
	}
}
