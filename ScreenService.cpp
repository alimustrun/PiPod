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
}

void ScreenService::displayCursor(unsigned long cursorPosition, std::vector<ListEntry> *entries)
{
    _cursorPosition = cursorPosition;
    bool hasPageChanged = _currentPage != _cursorPosition / MAX_NB_LINES;
    _currentPage = _cursorPosition / MAX_NB_LINES;
    if (hasPageChanged)
    {
        _screenDriver->drawList(entries, _cursorPosition);
        _screenDriver->displayFrame();
        _screenDriver->drawCursor(cursorPosition);
    }
    else
    {
        _screenDriver->drawCursor(cursorPosition);
        _screenDriver->displayPartialFrame(0, 0, CHAR_WIDTH, SCREEN_HEIGHT);
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