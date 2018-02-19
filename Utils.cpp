//
// Created by fritsch on 19/02/18.
//

#include <dirent.h>
#include "Utils.h"

void Utils::getFilesFromPath(std::vector<const char *> *filenames, const char *path)
{
    DIR* dirp = opendir(path);
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        filenames->push_back(dp->d_name);
    }
    closedir(dirp);
}
