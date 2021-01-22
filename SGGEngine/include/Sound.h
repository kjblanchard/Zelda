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

	struct MusicFile
	{
		std::string FileLocation;
		bool ShouldIntroLoop;
		unsigned int IntroLoopTimeBegin;
	};

	class SGGENGINE_API Sound
	{
	public:
		inline static std::map<MusicToPlay, MusicFile> MusicToLoadedMusicDict =
		{
			{MusicToPlay::Overworld, MusicFile{"assets/sound/Overworld",true,6170}   }
		};

		static void PlayMusic(MusicToPlay musicToPlayEnum);
		static Mix_Music* CurrentPlayingIntroMusic;
		static Mix_Music* CurrentPlayingMixMusic;
		static MusicFile CurrentPlayingMusicFile;

		static Uint32 callback(Uint32 interval, void* param)
		{
			auto loopFilename = CurrentPlayingMusicFile.FileLocation + "Loop.ogg";
			CurrentPlayingMixMusic = Mix_LoadMUS(loopFilename.c_str());
			Mix_PlayMusic(CurrentPlayingMixMusic, -1);
			return 0;
		}

		static void PlayMusicAfterWaitTime(MusicFile musicToPlay);
	};
}
