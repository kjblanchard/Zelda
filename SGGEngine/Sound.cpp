#include "pch.h"


#include  "Sound.h"

namespace SG
{
	Mix_Music* Sound::CurrentPlayingMusic = nullptr;
	void Sound::PlayMusic(MusicToPlay musicToPlayEnum)
	{
		CurrentPlayingMusic = Mix_LoadMUS(MusicToLoadedMusicDict.at(musicToPlayEnum).c_str());
		Mix_PlayMusic(CurrentPlayingMusic,-1);
	}
}
