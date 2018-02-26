//
// Created by fritsch on 16/02/18.
//

#ifndef PIPOD_LISTENTRY_H
#define PIPOD_LISTENTRY_H


#include <functional>
#include "FileType.h"

class ListEntry
{
public:
    ListEntry(std::string *name, FileType fileType, const std::function<void(void)> action);
    void executeAction();
    std::string *getName();
private:
    std::string *_name;
    FileType _fileType;
    std::function<void(void)> _action;
};


#endif //PIPOD_LISTENTRY_H
