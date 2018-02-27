//
// Created by fritsch on 14/02/18.
//

#include <iostream>
#include "ScreenService.h"

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
    _cursorPosition = 0;
    _screenDriver->drawList(entries, _cursorPosition);
    displayCursor(0, entries);
}

void ScreenService::displayCursor(unsigned long cursorPosition, std::vector<ListEntry> *entries, bool forceDisplayFrame)
{
    _cursorPosition = cursorPosition;
    bool hasPageChanged = _currentPage != _cursorPosition / MAX_NB_LINES;
    _currentPage = _cursorPosition / MAX_NB_LINES;
    if (hasPageChanged)
    {
        _screenDriver->drawList(entries, _cursorPosition);
        _screenDriver->drawCursor(cursorPosition);
        std::cout << "displayFrame()" << std::endl;
        _screenDriver->displayFrame();
    }
    else
    {
        _screenDriver->drawCursor(cursorPosition);
        if (forceDisplayFrame)
        {
            _screenDriver->displayFrame();
        }
        else
        {
            _screenDriver->displayPartialFrame(0, 0, SCREEN_HEIGHT, CHAR_HEIGHT);//reversing since there is a 90° rotation
        }
        std::cout << "displayPartialFrame()" << std::endl;
    }
}

void ScreenService::fullClear()
{
    _screenDriver->fullClear();
}

void ScreenService::quickClear()
{
    _screenDriver->quickClear();
}

void ScreenService::requestDisplay()
{
    _screenDriver->displayFrame();
}
