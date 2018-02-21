//
// Created by fritsch on 19/02/18.
//

#include <dirent.h>
#include <cstddef>
#include <cstring>
#include <iostream>
#include "Utils.h"

void Utils::getFilesFromPath(std::vector<std::string> *filenames, const char *path)
{
    DIR* dirp = opendir(path);
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        if (strlen(dp->d_name) > 1 && (dp->d_name[0] != '.' || (dp->d_name[0] == '.' && dp->d_name[1] == '.')))
        {
            filenames->push_back(std::string(dp->d_name));
            std::cout << "adding : " << dp->d_name << std::endl;
        }
    }
    closedir(dirp);
}
