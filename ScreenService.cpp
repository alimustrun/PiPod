//
// Created by fritsch on 14/02/18.
//

#include "ScreenService.h"
#include "ButtonsGPIO.h"

void ScreenService::start()
{
    this->_screenDriver = new ScreenDriver();
}

void ScreenService::stop()
{

}

void ScreenService::registerToKeyboardService()
{

}

void ScreenService::onKeyPressed(int key)
{
    return;
    switch (key)
    {
        case VOL_DEC:
            this->_screenDriver->displayText(const_cast<char *>("VOL_DEC"));
            break;
        case VOL_INC:
            this->_screenDriver->displayText(const_cast<char *>("VOL_INC"));
            break;
        case PREV:
            this->_screenDriver->displayText(const_cast<char *>("PREV"));
            break;
        case NEXT:
            this->_screenDriver->displayText(const_cast<char *>("NEXT"));
            break;
        case RIGHT:
            this->_screenDriver->displayText(const_cast<char *>("RIGHT"));
            break;
        case CENTER:
            this->_screenDriver->displayText(const_cast<char *>("CENTER"));
            break;
        case LEFT:
            this->_screenDriver->displayText(const_cast<char *>("LEFT"));
            break;
        default:
            break;
    }
}