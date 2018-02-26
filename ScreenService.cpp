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
    std::cout << "displayScrollableList 1" << std::endl;
    _screenDriver->displayList(entries, _cursorPosition);
    std::cout << "displayScrollableList 2" << std::endl;
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
    _screenDriver->displayCursor(cursorPosition);
}

void ScreenService::clearScreen()
{
    _screenDriver->fullClear();
}