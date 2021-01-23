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
#include <SDL_timer.h>
#include <string>
#include "SDL_mixer.h"


namespace SG
{
	enum class MusicToPlay
	{
		Default = 0,
		Overworld = 1,
	};

	struct MusicFile
	{
		std::string FileLocation;
		bool ShouldIntroLoop;
		double IntroLoopTimeBegin;
		double IntroLoopTimeEnd;
	};

	class SGGENGINE_API Sound
	{
	public:
		inline static std::map<MusicToPlay, MusicFile> MusicToLoadedMusicDict =
		{
			{MusicToPlay::Overworld, MusicFile{"assets/sound/Overworld.ogg",true,6.719, 51.418 }   }
		};

		static void PlayMusic(MusicToPlay musicToPlayEnum);
		static Mix_Music* CurrentPlayingMixMusic;
		static MusicFile CurrentPlayingMusicFile;

		static Uint32 callback(Uint32 interval, void* param)
		{
			Mix_SetMusicPosition(CurrentPlayingMusicFile.IntroLoopTimeBegin);
			auto timer = SDL_AddTimer((CurrentPlayingMusicFile.IntroLoopTimeEnd - CurrentPlayingMusicFile.IntroLoopTimeBegin + 0.05) * 1000, callback, nullptr);
			return 0;
		}
		static SDL_TimerID CurrentMusicTimer;
	};
}
