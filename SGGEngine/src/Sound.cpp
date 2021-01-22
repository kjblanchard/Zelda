#include "pch.h"


#include  "Sound.h"

#include <future>
#include <iostream>
#include <ostream>
#include <SDL_timer.h>

namespace SG
{
	//statics
	Mix_Music* Sound::CurrentPlayingMixMusic = nullptr;
	MusicFile Sound::CurrentPlayingMusicFile;
	Mix_Music* Sound::CurrentPlayingIntroMusic;

	void Sound::PlayMusic(MusicToPlay musicToPlayEnum)
	{
		CurrentPlayingMusicFile = MusicToLoadedMusicDict.at(musicToPlayEnum);
		if (!CurrentPlayingMusicFile.FileLocation.empty())
		{
			if (CurrentPlayingMusicFile.ShouldIntroLoop)
			{
				auto introFilename = CurrentPlayingMusicFile.FileLocation + "Intro.ogg";
				printf(introFilename.c_str());
				auto intro = Mix_LoadMUS(introFilename.c_str());

				Mix_PlayMusic(intro, 1);
				auto timerID = SDL_AddTimer(CurrentPlayingMusicFile.IntroLoopTimeBegin, callback, nullptr);
			}

			else
				CurrentPlayingMixMusic = Mix_LoadMUS(CurrentPlayingMusicFile.FileLocation.c_str());
				Mix_PlayMusic(CurrentPlayingMixMusic, -1);

		}

	}

	void Sound::PlayMusicAfterWaitTime(MusicFile musicToPlay)
	{
		Mix_FadeInMusicPos(CurrentPlayingMixMusic, -1, 0.0, 20.0);
	}
}
