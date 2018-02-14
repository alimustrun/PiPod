//
// Created by fritsch on 13/02/18.
//

#include <wiringPi.h>
#include <iostream>
#include "KeyboardService.h"

enum ButtonsGPIO {
    RIGHT = 4,
    CENTER = 14,
    LEFT = 15,
    NEXT = 26,
    PREV = 20,
    VOL_INC = 27,
    VOL_DEC = 22
};
//https://hackage.haskell.org/package/wiringPi

void KeyboardService::start()
{
    wiringPiSetupGpio();
    this->buttonsStatuses->insert(std::make_pair(RIGHT, this->isKeyPressed(RIGHT)));
    this->buttonsStatuses->insert(std::make_pair(LEFT, this->isKeyPressed(LEFT)));
    this->buttonsStatuses->insert(std::make_pair(CENTER, this->isKeyPressed(CENTER)));
    this->buttonsStatuses->insert(std::make_pair(VOL_DEC, this->isKeyPressed(VOL_DEC)));
    this->buttonsStatuses->insert(std::make_pair(VOL_INC, this->isKeyPressed(VOL_INC)));
    this->buttonsStatuses->insert(std::make_pair(NEXT, this->isKeyPressed(NEXT)));
    this->buttonsStatuses->insert(std::make_pair(PREV, this->isKeyPressed(PREV)));

    pullUpDnControl(RIGHT, PUD_UP);
    pullUpDnControl(CENTER, PUD_UP);
    pullUpDnControl(LEFT, PUD_UP);
    pullUpDnControl(VOL_INC, PUD_UP);
    pullUpDnControl(VOL_DEC, PUD_UP);
    pullUpDnControl(NEXT, PUD_UP);
    pullUpDnControl(PREV, PUD_UP);
}

void KeyboardService::stop()
{
    //cancel timer
}

void KeyboardService::refreshKeys()
{
    auto it = this->buttonsStatuses->begin();
    while (it != this->buttonsStatuses->end())
    {
        it->second = this->isKeyPressed(it->first);
	++it;
    }
}

void KeyboardService::printKeysStatuses()
{
    auto it = this->buttonsStatuses->begin();
    while (it != this->buttonsStatuses->end())
    {
        if (it->second)
        {
	  std::cout << it->first << " : true" << std::endl;
        }
	else
	  {
	    std::cout << it->first << " : false" << std::endl;
	  }
	++it;
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
