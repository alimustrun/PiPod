//
// Created by fritsch on 27/02/18.
//

#include <iostream>
#include "MusicFile.h"

MusicFile::MusicFile(const char *fullPath, std::string *artistName, std::string *albumName, std::string *title,
                     unsigned int length, unsigned int bitrate, MusicExtension musicExtension) : _fullPath(fullPath),
                                                                                                 _artist(artistName),
                                                                                                 _album(albumName),
                                                                                                 _title(title),
                                                                                                 _length(length),
                                                                                                 _bitrate(bitrate),
                                                                                                 _musicExtension(
                                                                                                         musicExtension)
{
}

std::string *MusicFile::getArtist()
{
    return _artist;
}

std::string *MusicFile::getAlbum()
{
    return _album;
}

std::string *MusicFile::getTitle()
{
    return _title;
}

const unsigned int MusicFile::getLength()
{
    return _length;
}

const unsigned int MusicFile::getBitrate()
{
    return _bitrate;
}

MusicExtension MusicFile::getMusicExtension()
{
    return _musicExtension;
}
