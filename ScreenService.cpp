//
// Created by fritsch on 14/02/18.
//

#include "ScreenService.h"
#include "ButtonsGPIO.h"

void ScreenService::start()
{
    this->_screenDriver = new ScreenDriver();
    this->_cursorPosition = 0;
}

void ScreenService::stop()
{

}

void ScreenService::displayBootScreen()
{
    _screenDriver->displayBootScreen();
}

void ScreenService::displayScrollableList(std::vector<ListEntry> *entries)
{
    _screenDriver->displayList(entries, _cursorPosition);
}

void ScreenService::displayCursor(unsigned long cursorPosition, std::vector<ListEntry> *entries)
{
    _cursorPosition = cursorPosition;
    bool hasPageChanged = _currentPage != _cursorPosition / MAX_NB_LINES;
    _currentPage = _cursorPosition / MAX_NB_LINES;
    if (hasPageChanged)
    {
        _screenDriver->displayList(entries, _cursorPosition);
    }
    _screenDriver->displayCursor(cursorPosition, entries->size());
}

void ScreenService::clearScreen()
{
    _screenDriver->fullClear();
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

void ScreenService::refreshCursor(unsigned long currentSelection, unsigned long listSize)
{

}
