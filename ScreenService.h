//
// Created by fritsch on 14/02/18.
//

#ifndef PIPOD_SCREENSERVICE_H
#define PIPOD_SCREENSERVICE_H

#include <thread>
#include "screen-driver/ScreenDriver.h"
#include "Service.h"

class ScreenService : Service
{
public:
    void start() override;
    void stop() override;
    void displayBootScreen();
    void displayScrollableList(std::vector<ListEntry> *entries);
    void displayCursor(unsigned long cursorPosition, std::vector<ListEntry> *entries, bool forceDisplayFrame);
    void fullClear();

    void quickClear();

    void requestDisplay();

private:
    ScreenDriver *_screenDriver = nullptr;
    unsigned long _cursorPosition = 0;
    unsigned long _currentPage = 0;
};


#endif //PIPOD_SCREENSERVICE_H
