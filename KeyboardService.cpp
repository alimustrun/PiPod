//
// Created by fritsch on 13/02/18.
//

#include <wiringPi.h>
#include <iostream>
#include "KeyboardService.h"
#include "ButtonsGPIO.h"

void KeyboardService::start()
{
    wiringPiSetupGpio();
    this->_buttonsStatuses->insert(std::make_pair(RIGHT, this->isKeyPressed(RIGHT)));
    this->_buttonsStatuses->insert(std::make_pair(LEFT, this->isKeyPressed(LEFT)));
    this->_buttonsStatuses->insert(std::make_pair(CENTER, this->isKeyPressed(CENTER)));
    this->_buttonsStatuses->insert(std::make_pair(VOL_DEC, this->isKeyPressed(VOL_DEC)));
    this->_buttonsStatuses->insert(std::make_pair(VOL_INC, this->isKeyPressed(VOL_INC)));
    this->_buttonsStatuses->insert(std::make_pair(NEXT, this->isKeyPressed(NEXT)));
    this->_buttonsStatuses->insert(std::make_pair(PREV, this->isKeyPressed(PREV)));

    for (auto &buttonsStatuse : *this->_buttonsStatuses)
    {
        pullUpDnControl(buttonsStatuse.first, PUD_UP);
    }
}

void KeyboardService::stop()
{
    //cancel timer
}

void KeyboardService::refreshKeys()
{
    for (auto &buttonsStatuse : *this->_buttonsStatuses)
    {
        buttonsStatuse.second = this->isKeyPressed(buttonsStatuse.first);
        if (buttonsStatuse.second)
        {
            this->notifyListeners(buttonsStatuse.first);
        }
    }
}

const bool KeyboardService::isKeyPressed(int key) const
{
    return digitalRead(key) == LOW;
}

KeyboardService::~KeyboardService()
{
    delete this->_buttonsStatuses;
    delete this->_keyboardListeners;
}

KeyboardService::KeyboardService()
{
    this->_buttonsStatuses = new std::map<int, bool>;
    this->_keyboardListeners = new std::list<std::function<void(int)>>;
}


void KeyboardService::notifyListeners(const int i)
{
    for (auto &keyboardListeners : *this->_keyboardListeners)
    {
        keyboardListeners(i);
    }
}

void KeyboardService::addListener(std::function<void(int)> listener)
{
    this->_keyboardListeners->push_back(listener);
}

void KeyboardService::removeListener(std::function<void(int)> listener)
{
}