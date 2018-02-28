//
// Created by fritsch on 27/02/18.
//

#ifndef PIPOD_MUSICFILE_H
#define PIPOD_MUSICFILE_H

#include <string>

class MusicFile
{
public:
    MusicFile(const char *fullPath, std::string *artistName, std::string *albumName);

    std::string *getArtistName();

    std::string *getAlbumName();

private:
    const char *fullPath;
    std::string *_artistName;
    std::string *_albumName;

};


#endif //PIPOD_MUSICFILE_H
