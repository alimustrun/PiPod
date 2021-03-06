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
    void displayScrollableList(std::vector<ListEntry> *entries);
    void displayCursor(unsigned long cursorPosition, std::vector<ListEntry> *entries);

    void refreshCursor(unsigned long currentSelection, unsigned long listSize);

    void clearScreen();

private:
    ScreenDriver *_screenDriver = nullptr;

    unsigned long _cursorPosition;
    unsigned long _currentPage;

};


#endif //PIPOD_SCREENSERVICE_H
