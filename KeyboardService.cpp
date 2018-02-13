//
// Created by fritsch on 13/02/18.
//

#include <wiringPi.h>
#include "KeyboardService.h"

void KeyboardService::start()
{
    wiringPiSetupGpio();
    //register to keyboard events
}

void KeyboardService::stop()
{
    //unregister to keyboard events
}