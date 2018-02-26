//
// Created by fritsch on 16/02/18.
//

#include "ListEntry.h"

ListEntry::ListEntry(std::string *name, FileType fileType, const std::function<void(void)> action)
{
    this->_name = name;
    this->_action = action;
    this->_fileType = fileType;
}

void ListEntry::executeAction()
{
    _action();

}

std::string *ListEntry::getName()
{
    return _name;
}
