//
// Created by fritsch on 11/02/18.
//

#ifndef PIPOD_SCREENDRIVER_H
#define PIPOD_SCREENDRIVER_H

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "epd2in13.h"
#include "epdpaint.h"
#include "imagedata.h"

#define COLORED      0
#define UNCOLORED    1

class ScreenDriver
{
public:
    ScreenDriver();

    const void displaySomething();
    const void displayText(char *);

private:
    Epd *_epd;
};

#endif //PIPOD_SCREENDRIVER_H
