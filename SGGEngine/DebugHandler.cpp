#include "pch.h"
#include  "DebugHandler.h"
#include <SDL_image.h>

namespace SG
{

	void DebugHandler::PrintErrorMessage(ErrorCodes codeToPrint)
	{
		switch (codeToPrint)
		{
		case ErrorCodes::GenericError:
			printf("Generic Error");
			break;
		case ErrorCodes::SDLError: break;
		case ErrorCodes::SDLImageError:
			printf("Unable to load image! SDL_image Error: %s\n", IMG_GetError());
			break;
		case ErrorCodes::SDLTextureError:
			printf("Unable to create texture! SDL Error: %s\n", SDL_GetError());
			break;
		}
	}

}
