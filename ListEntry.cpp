//
// Created by fritsch on 16/02/18.
//

#include "ListEntry.h"

ListEntry::ListEntry(const char *name, const std::function<void(void)> *action)
{
    this->_name = name;
    this->_action = action;
}

void ListEntry::executeAction()
{
    std::function<void(void)> action = _action;
    action();
}
