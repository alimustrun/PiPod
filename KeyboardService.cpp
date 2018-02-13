//
// Created by fritsch on 13/02/18.
//

#include <wiringPi.h>
#include "KeyboardService.h"

enum Buttons {
    RIGHT = 7,
    CENTER = 15,
    LEFT = 16,
    NEXT = 2,
    PREV = 38,
    VOL_INC = 3,
    VOL_DEC = 25
};
//https://hackage.haskell.org/package/wiringPi

void KeyboardService::start()
{
    wiringPiSetupGpio();
    //register to keyboard events
    bool rightPressed = HIGH == digitalRead(RIGHT);
    bool leftPressed = HIGH == digitalRead(LEFT);
    bool centerPressed = HIGH == digitalRead(CENTER);
    bool nextPressed = HIGH == digitalRead(NEXT);
    bool prevPressed = HIGH == digitalRead(PREV);
    bool volIncPressed = HIGH == digitalRead(VOL_INC);
    bool volDecPressed = HIGH == digitalRead(VOL_DEC);
}

void KeyboardService::stop()
{
    //unregister to keyboard events
}

void KeyboardService::setup()
{
    pullUpDnControl(7, PUD_UP);//7; GPIO4
    pullUpDnControl(15, PUD_UP);//8; GPIO 14
    pullUpDnControl(16, PUD_UP);//10; GPIO 15
    pullUpDnControl(2, PUD_UP);//13; GPIO 27
    pullUpDnControl(3, PUD_UP);//15; GPIO 22
    pullUpDnControl(25, PUD_UP);//37; GPIO 26
    pullUpDnControl(28, PUD_UP);//38; GPIO 38
}