////////////////////////////////////////////////////////////
//
// Super Goon Games - 2D Game Engine
// Copyright (C) 2020-2021 - Kevin Blanchard
//
////////////////////////////////////////////////////////////

#pragma once
#ifdef SGGENGINE_EXPORTS
#define SGGENGINE_API __declspec(dllexport)
#else
#define SGGENGINE_API __declspec(dllimport)
#endif
#include <map>
#include <string>

using std::string;

namespace SG
{
	enum class ErrorCodes
	{
		GenericError = 0,
		SDLError = 1,
		SDLImageError =2,
		SDLTextureError = 3

	};


	class SGGENGINE_API DebugHandler
	{
	public:

		static void PrintErrorMessage(ErrorCodes codeToPrint);
	};
}
