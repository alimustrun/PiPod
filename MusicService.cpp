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
    _currentMusic = new MusicFile(path, new std::string("Azerty"), new std::string("Uiop"));
    std::cout << "Playing music at given path." << std::endl;
}

MusicFile *MusicService::getPlayingMusic()
{
    return _currentMusic;
}

MusicService::MusicService()
{

}
