//
// Created by fritsch on 19/02/18.
//

#ifndef PIPOD_UTILS_H
#define PIPOD_UTILS_H


#include <vector>
#include "FileType.h"

class Utils
{
public:
    static void getFilesFromPath(std::vector<std::pair<std::string, FileType>> *filenames, const char *path);
    static FileType getFileType(dirent *dp);
    static std::string * resolvePath(const char *pathToResolve);
    static std::string *changeDirectory(const char *currentPath, const char *newDirectoryName);
};


#endif //PIPOD_UTILS_H
