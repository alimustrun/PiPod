//
// Created by fritsch on 11/02/18.
//

#ifndef PIPOD_SCREENDRIVER_H
#define PIPOD_SCREENDRIVER_H

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "epd2in13.h"
#include "epdpaint.h"
#include "imagedata.h"
#include "../ListEntry.h"

#define COLORED      0
#define UNCOLORED    1

#define CHAR_HEIGHT 16
#define CHAR_WIDTH 16
#define SCREEN_HEIGHT 128
#define MAX_NB_LINES ((int)(SCREEN_HEIGHT / CHAR_HEIGHT) - 1)
#define FONT &Font16


class ScreenDriver
{
public:
    ScreenDriver();

    const void displaySomething();
    const void displayText(std::string *);
    const void displayBootScreen();
    const void displayCursor(unsigned long currentSelection, unsigned long nbSelections);
    const void displayList(std::vector<ListEntry> *entries, unsigned long currentCursorPosition);

    const void fullClear();

private:

    Epd *_epd;
    unsigned char *_frame_buffer;
    Paint *_paint;
};

#endif //PIPOD_SCREENDRIVER_H
