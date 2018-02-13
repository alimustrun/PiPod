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
    //launch a timer to poll keyboard events
}

void KeyboardService::stop()
{
    //cancel timer
}

void KeyboardService::setup()
{
    this->buttonsStatuses->insert(std::make_pair(this->isKeyPressed(RIGHT), RIGHT));
    this->buttonsStatuses->insert(std::make_pair(this->isKeyPressed(LEFT), LEFT));
    this->buttonsStatuses->insert(std::make_pair(this->isKeyPressed(CENTER), CENTER));
    this->buttonsStatuses->insert(std::make_pair(this->isKeyPressed(VOL_DEC), VOL_DEC));
    this->buttonsStatuses->insert(std::make_pair(this->isKeyPressed(VOL_INC), VOL_INC));
    this->buttonsStatuses->insert(std::make_pair(this->isKeyPressed(NEXT), NEXT));
    this->buttonsStatuses->insert(std::make_pair(this->isKeyPressed(PREV), PREV));

    pullUpDnControl(RIGHT, PUD_UP);//7; GPIO4
    pullUpDnControl(CENTER, PUD_UP);//8; GPIO 14
    pullUpDnControl(LEFT, PUD_UP);//10; GPIO 15
    pullUpDnControl(VOL_INC, PUD_UP);//13; GPIO 27
    pullUpDnControl(VOL_DEC, PUD_UP);//15; GPIO 22
    pullUpDnControl(NEXT, PUD_UP);//37; GPIO 26
    pullUpDnControl(PREV, PUD_UP);//38; GPIO 38
}

void KeyboardService::refreshKeys()
{
    auto it = this->buttonsStatuses->begin();
    while (it != this->buttonsStatuses->end())
    {
        it->second = this->isKeyPressed(it->first);
    }
}

const bool KeyboardService::isKeyPressed(int key) const
{
    return digitalRead(key) == HIGH;
}

KeyboardService::~KeyboardService()
{
    delete this->buttonsStatuses;
}

KeyboardService::KeyboardService()
{
    this->buttonsStatuses = new std::map<int, bool>;
}
