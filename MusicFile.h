//
// Created by fritsch on 27/02/18.
//

#ifndef PIPOD_MUSICFILE_H
#define PIPOD_MUSICFILE_H

#include <string>
#include "MusicExtension.h"

class MusicFile
{
public:
    MusicFile(const char *fullPath, std::string *_artist, std::string *_album, std::string *title, unsigned int _length,
              unsigned int _bitrate, MusicExtension _musicExtension);

    std::string *getArtist();
    std::string *getAlbum();
    std::string *getTitle();
    const unsigned int getLength();
    const unsigned int getBitrate();
    MusicExtension getMusicExtension();

private:
    const char *_fullPath;
    std::string *_artist;
    std::string *_album;
    std::string *_title;
    unsigned int _length;
    unsigned int _bitrate;
    MusicExtension _musicExtension;
};


#endif //PIPOD_MUSICFILE_H
