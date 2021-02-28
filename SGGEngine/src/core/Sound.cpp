
#include "pch.h"

#pragma warning(push)
#pragma warning(disable : 4244)
#include  "core/Sound.h"

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

	void Sound::PlaySound(SoundFxToPlay soundToPlayEnum)
	{
		auto soundToPlay = SoundFxToLoadedSoundDict.at(soundToPlayEnum);
		if(soundToPlay.LoadedSound == NULL)
		{
			SoundFxToLoadedSoundDict.at(soundToPlayEnum).LoadedSound = Mix_LoadWAV(soundToPlay.FileLocation.c_str());
			if(soundToPlay.LoadedSound == NULL)
				printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
			Mix_PlayChannel(-1, SoundFxToLoadedSoundDict.at(soundToPlayEnum).LoadedSound, 0);
		}
		else
			Mix_PlayChannel(-1, soundToPlay.LoadedSound, 0);

	}
}

#pragma warning(pop)
