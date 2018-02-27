//
// Created by fritsch on 19/02/18.
//

#include <dirent.h>
#include <cstddef>
#include <cstring>
#include <utility>
#include <iostream>
#include "Utils.h"

void Utils::getFilesFromPath(std::vector<std::pair<std::string, FileType>> *filenames, const char *path)
{
    DIR* dirp = opendir(path);
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        if (strlen(dp->d_name) > 1 && dp->d_name[0] != '.')
        {
            filenames->push_back(std::make_pair(std::string(dp->d_name), getFileType(dp)));
        }
    }
    closedir(dirp);
}

FileType Utils::getFileType(dirent *dp)
{
    switch (dp->d_type)
    {
        case DT_REG:
            return FileType::TYPE_FILE;
        case DT_DIR:
            return FileType::TYPE_DIRECTORY;
        default:
            return FileType::TYPE_NA;
    }
}

std::string *Utils::changeDirectory(const char *currentPath, const char *newDirectoryName)
{
    std::string temporaryPath = std::string(currentPath);
    temporaryPath.append("/").append(newDirectoryName);
    return resolvePath(temporaryPath.c_str());
}

std::string *Utils::resolvePath(const char *pathToResolve)
{
    std::string *resolvedPath;
    auto *realPath = static_cast<char *>(malloc(sizeof(char) * 1024));

    realpath(pathToResolve, realPath);
    resolvedPath = new std::string(realPath);

    free(realPath);

    return resolvedPath;
}
