//
// Created by fritsch on 27/02/18.
//

#include <iostream>
#include "MusicFile.h"

MusicFile::MusicFile(const char *fullPath, std::string *artistName, std::string *albumName) : fullPath(fullPath),
                                                                                              _artistName(artistName),
                                                                                              _albumName(albumName)
{
    std::cout << "Creating MusicFile, path = " << fullPath << std::endl;
}

std::string *MusicFile::getArtistName()
{
    return _artistName;
}

std::string *MusicFile::getAlbumName()
{
    return _albumName;
}
