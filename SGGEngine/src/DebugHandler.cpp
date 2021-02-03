
#include "pch.h"
#pragma warning(push)
#pragma warning(disable : 26819)
#include  "DebugHandler.h"

#include <SDL_image.h>
#include <SDL_mixer.h>

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
		case ErrorCodes::GameSlowdown:
			printf("Game is currently getting worse than normal FPS, current ms delay between frames (should be 16.6667) : ");
			break;
		case ErrorCodes::SDLSpriteSheetError:
			printf("You probably entered in the wrong spritesheet name, or forgot to add it to tne enum with its proper filename in graphics");
			break;
		case ErrorCodes::SDLMixerError:
			printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
			break;
		case ErrorCodes::AnimationError:
			printf("Somehow there isn't a valid animation, probably forgot some boilerplate in the enum, etc");
		default: break;
		}
	}

}

#pragma warning(pop)