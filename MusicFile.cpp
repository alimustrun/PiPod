//
// Created by fritsch on 27/02/18.
//

#include <iostream>
#include "MusicFile.h"

MusicFile::MusicFile(const char *fullPath, std::string *artistName, std::string *albumName) : fullPath(fullPath),
                                                                                              artistName(artistName),
                                                                                              albumName(albumName)
{
    std::cout << "Creating MusicFile, path = " << fullPath << std::endl;
}
