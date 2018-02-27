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

private:
    const char *fullPath;
    std::string *artistName;
    std::string *albumName;
};


#endif //PIPOD_MUSICFILE_H
