//
// Created by fritsch on 27/02/18.
//

#include <iostream>
#include "MusicService.h"

void MusicService::start()
{

}

void MusicService::stop()
{

}

void MusicService::playMusicAtGivenPath(const char *path)
{
    _currentMusic = new MusicFile(path, new std::string("Artist"), new std::string("Album"), new std::string("Title"), 40 + 60 * 3, 320, MP3);
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
    std::cout << "amixer set Digital 5%-" << std::endl;
    system("amixer set Digital 5%-");
}

void MusicService::increaseVolumeClicked()
{
    std::cout << "amixer set Digital 5%+" << std::endl;
    system("amixer set Digital 5%+");
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
