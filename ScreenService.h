//
// Created by fritsch on 14/02/18.
//

#ifndef PIPOD_SCREENSERVICE_H
#define PIPOD_SCREENSERVICE_H


#include "Service.h"

class ScreenService : Service
{
public:
    void start() override;
    void stop() override;
    void registerToKeyboardService();
};


#endif //PIPOD_SCREENSERVICE_H
