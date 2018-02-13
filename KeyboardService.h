//
// Created by fritsch on 13/02/18.
//

#ifndef PIPOD_KEYBOARDSERVICE_H
#define PIPOD_KEYBOARDSERVICE_H


#include <map>
#include "Service.h"

class KeyboardService : Service
{
public:
    KeyboardService();
    ~KeyboardService();
    void start() override;
    void stop() override;
private:
    void setup() override;
    const bool isKeyPressed(int key) const;

    std::map<int, bool> *buttonsStatuses;

    void refreshKeys();
};


#endif //PIPOD_KEYBOARDSERVICE_H
