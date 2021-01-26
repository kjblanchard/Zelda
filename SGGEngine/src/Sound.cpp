
#include "pch.h"

#pragma warning(push)
#pragma warning(disable : 4244)
#include  "Sound.h"

#include <future>

namespace SG
{
	//statics
	Mix_Music* Sound::CurrentPlayingMixMusic = nullptr;
	MusicFile Sound::CurrentPlayingMusicFile;
	SDL_TimerID Sound::CurrentMusicTimer;

	void Sound::PlayMusic(MusicToPlay musicToPlayEnum)
	{
		CurrentPlayingMusicFile = MusicToLoadedMusicDict.at(musicToPlayEnum);
		if (!CurrentPlayingMusicFile.FileLocation.empty())
		{
			CurrentPlayingMixMusic = Mix_LoadMUS(CurrentPlayingMusicFile.FileLocation.c_str());

			if (CurrentPlayingMusicFile.ShouldIntroLoop)
			{
				Mix_PlayMusic(CurrentPlayingMixMusic, -1);
				CurrentMusicTimer = SDL_AddTimer(CurrentPlayingMusicFile.IntroLoopTimeEnd * 1000, ContinuouslyLoopMusic, nullptr);
			}
			else
				Mix_PlayMusic(CurrentPlayingMixMusic, -1);

		}

	}

}

#pragma warning(pop)
