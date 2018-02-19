//
// Created by fritsch on 19/02/18.
//

#ifndef PIPOD_UTILS_H
#define PIPOD_UTILS_H


#include <vector>

class Utils
{
public:
    static void getFilesFromPath(std::vector<const char *> *filenames, const char *path);
};


#endif //PIPOD_UTILS_H
