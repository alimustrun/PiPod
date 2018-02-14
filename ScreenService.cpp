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
    switch (key)
    {
        case VOL_DEC:
            this->_screenDriver->displayText(new std::string("VOL_DEC"));
            break;
        case VOL_INC:
            this->_screenDriver->displayText(new std::string("VOL_INC"));
            break;
        case PREV:
            this->_screenDriver->displayText(new std::string("PREV"));
            break;
        case NEXT:
            this->_screenDriver->displayText(new std::string("NEXT"));
            break;
        case RIGHT:
            this->_screenDriver->displayText(new std::string("RIGHT"));
            break;
        case CENTER:
            this->_screenDriver->displayText(new std::string("CENTER"));
            break;
        case LEFT:
            this->_screenDriver->displayText(new std::string("LEFT"));
            break;
        default:
            break;
    }
}