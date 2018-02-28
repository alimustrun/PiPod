//
// Created by fritsch on 27/02/18.
//

#include "MusicService.h"

void MusicService::start()
{

}

void MusicService::stop()
{

}

void MusicService::playMusicAtGivenPath(const char *path)
{
    _currentMusic = new MusicFile(path, new std::string("Azerty"), new std::string("Uiop"));
}

MusicFile *MusicService::getPlayingMusic()
{
    return _currentMusic;
}

MusicService::MusicService()
{

}

void MusicService::decreaseVolumeClicked()
{

}

void MusicService::increaseVolumeClicked()
{

}

void MusicService::playPreviousSongClicked()
{

}

void MusicService::playNextSongClicked()
{

}

void MusicService::playClicked()
{

}
