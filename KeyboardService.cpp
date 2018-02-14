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
    this->buttonsStatuses->insert(std::make_pair(RIGHT, this->isKeyPressed(RIGHT)));
    this->buttonsStatuses->insert(std::make_pair(LEFT, this->isKeyPressed(LEFT)));
    this->buttonsStatuses->insert(std::make_pair(CENTER, this->isKeyPressed(CENTER)));
    this->buttonsStatuses->insert(std::make_pair(VOL_DEC, this->isKeyPressed(VOL_DEC)));
    this->buttonsStatuses->insert(std::make_pair(VOL_INC, this->isKeyPressed(VOL_INC)));
    this->buttonsStatuses->insert(std::make_pair(NEXT, this->isKeyPressed(NEXT)));
    this->buttonsStatuses->insert(std::make_pair(PREV, this->isKeyPressed(PREV)));

    for (auto &buttonsStatuse : *this->buttonsStatuses)
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
    for (auto &buttonsStatuse : *this->buttonsStatuses)
    {
        bool buttonCurrentStatus = this->isKeyPressed(buttonsStatuse.first);
        if (buttonCurrentStatus != buttonsStatuse.second)
        {
            buttonsStatuse.second = buttonCurrentStatus;
            this->notifyListeners();
        }
    }
}

void KeyboardService::printKeysStatuses()
{
    for (auto &buttonsStatuse : *this->buttonsStatuses)
    {
        std::cout << buttonsStatuse.first << buttonsStatuse.second << std::endl;
    }
}

const bool KeyboardService::isKeyPressed(int key) const
{
    return digitalRead(key) == HIGH;
}

KeyboardService::~KeyboardService()
{
    delete this->buttonsStatuses;
    delete this->keyboardListeners;
}

KeyboardService::KeyboardService()
{
    this->buttonsStatuses = new std::map<int, bool>;
    this->keyboardListeners = new std::list<std::function<void(int)>>;
}

void KeyboardService::notifyListeners()
{
    for (auto &keyboardListeners : *this->keyboardListeners)
    {
    }
}
