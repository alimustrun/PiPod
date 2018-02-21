//
// Created by fritsch on 19/02/18.
//

#include <dirent.h>
#include <cstddef>
#include <cstring>
#include "Utils.h"

void Utils::getFilesFromPath(std::vector<const char *> *filenames, const char *path)
{
    DIR* dirp = opendir(path);
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        if (strlen(dp->d_name) > 1 && (dp->d_name[0] != '.' || (dp->d_name[0] == '.' && dp->d_name[1] == '.')))
        {
            filenames->push_back(dp->d_name);
        }
    }
    closedir(dirp);
}
