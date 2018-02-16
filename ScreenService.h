//
// Created by fritsch on 14/02/18.
//

#ifndef PIPOD_SCREENSERVICE_H
#define PIPOD_SCREENSERVICE_H

#include "screen-driver/ScreenDriver.h"
#include "Service.h"

class ScreenService : Service
{
public:
    void start() override;
    void stop() override;
    void onKeyPressed(int key);
    void displayBootScreen();
    void displayMainScreen();
    void displayCursor(int cursorPosition, int nbSelections);

private:
    ScreenDriver *_screenDriver = nullptr;

};


#endif //PIPOD_SCREENSERVICE_H
