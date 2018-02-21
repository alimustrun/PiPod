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