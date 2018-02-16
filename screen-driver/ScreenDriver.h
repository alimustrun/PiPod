//
// Created by fritsch on 11/02/18.
//

#ifndef PIPOD_SCREENDRIVER_H
#define PIPOD_SCREENDRIVER_H

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include "epd2in13.h"
#include "epdpaint.h"
#include "imagedata.h"

#define COLORED      0
#define UNCOLORED    1

#define NB_MAX_ROWS  5

class ScreenDriver
{
public:
    ScreenDriver();

    const void displaySomething();
    const void displayText(std::string *);
    const void displayBootScreen();
    const void displayMainScreen();
    const void displayCursor(int currentSelection, int nbSelections);

private:
    const void fullClear();

    Epd *_epd;
    unsigned char *_frame_buffer;
    Paint *_paint;
};

#endif //PIPOD_SCREENDRIVER_H
