//
// Created by fritsch on 27/02/18.
//

#ifndef PIPOD_MUSICSERVICE_H
#define PIPOD_MUSICSERVICE_H


#include "Service.h"
#include "MusicFile.h"

class MusicService : Service
{
public:
    MusicService();
    void playMusicAtGivenPath(const char *path);
    MusicFile *getPlayingMusic();

    void start() override;

    void decreaseVolumeClicked();

    void increaseVolumeClicked();

    void playPreviousSongClicked();

    void playNextSongClicked();

    void playClicked();

private:
    void stop() override;

    MusicFile *_currentMusic = nullptr;
};


#endif //PIPOD_MUSICSERVICE_H
