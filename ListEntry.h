//
// Created by fritsch on 16/02/18.
//

#ifndef PIPOD_LISTENTRY_H
#define PIPOD_LISTENTRY_H


#include <functional>

class ListEntry
{
public:
    ListEntry(const char *name, const std::function<void(void)> action);
    void executeAction();
    const char *getName();
private:
    const char *_name;
    std::function<void(void)> _action;
};


#endif //PIPOD_LISTENTRY_H
