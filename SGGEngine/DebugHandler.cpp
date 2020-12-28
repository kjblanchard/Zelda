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
		case ErrorCodes::SDLError:
			printf("SDL error: %s\n", IMG_GetError());
			break;
		case ErrorCodes::SDLImageError:
			printf("SDL_ImageError SDL_image Error: %s\n", IMG_GetError());
			break;
		case ErrorCodes::SDLTextureError:
			printf("Unable to create texture! SDL Error: %s\n", SDL_GetError());
			break;
		case ErrorCodes::WindowError:
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			break;
		default: ;
		}
	}

}
