//
// Created by fritsch on 13/02/18.
//

#ifndef PIPOD_KEYBOARDSERVICE_H
#define PIPOD_KEYBOARDSERVICE_H

#include <list>
#include <map>
#include <functional>
#include "Service.h"

class KeyboardService : Service
{
public:
    KeyboardService();
    ~KeyboardService();
    void start() override;
    void stop() override;
    void printKeysStatuses();
    void refreshKeys();
    void addListener(std::function<void(int)>);
    void removeListener(std::function<void(int)> listener);

private:
    const bool isKeyPressed(int key) const;
    void notifyListeners(const int i);

    std::map<int, bool> *_buttonsStatuses;
    std::list<std::function<void(int)>> *_keyboardListeners;
};


#endif //PIPOD_KEYBOARDSERVICE_H
