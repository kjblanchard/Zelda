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
#include "SDL_mixer.h"


namespace SG
{
	enum class MusicToPlay
	{
		Default = 0,
		Overworld = 1,
	};

	class SGGENGINE_API Sound
	{
	public:
		inline static std::map<MusicToPlay, std::string> MusicToLoadedMusicDict =
		{
			{MusicToPlay::Overworld,"assets/sound/Overworld.ogg"}
		};

		static void PlayMusic(MusicToPlay musicToPlayEnum);
		static Mix_Music* CurrentPlayingMusic;
	};
}
