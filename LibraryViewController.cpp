//
// Created by fritsch on 16/02/18.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include "LibraryViewController.h"
#include "ButtonsGPIO.h"
#include "Utils.h"

LibraryViewController::LibraryViewController(ScreenService *screenService)
{
    this->_screenService = screenService;
    this->_currentSelection = 0;
    this->_entriesList = new std::vector<ListEntry>;
    this->initEntriesList();
}

const void LibraryViewController::onKeyPressed(int key)
{
    switch (key)
    {
        case VOL_DEC:
            this->_currentSelection = this->_currentSelection < _entriesList->size() - 1 ? this->_currentSelection + 1 : this->_currentSelection;
            refreshCursor();
            //move cursor down
            break;
        case VOL_INC:
            this->_currentSelection = this->_currentSelection > 0 ? this->_currentSelection - 1 : 0;
            refreshCursor();
            //move cursor up
            break;
        case PREV:
            _requestView(Views::MAIN_MENU);
            break;
        case NEXT:
            _entriesList->at(_currentSelection).executeAction();
            //open subdirectory
            break;
        case RIGHT:
            break;
        case CENTER:
            break;
        case LEFT:
            break;
        default:
            break;
    }
}

void LibraryViewController::refreshCursor()
{
    this->_screenService->displayCursor(this->_currentSelection, _entriesList);
}

void LibraryViewController::initEntriesList()
{
    auto *rawFilenames = new std::vector<std::string>;
    Utils::getFilesFromPath(rawFilenames, "/home/pi/");
    for (const auto &rawFilename : *rawFilenames)
    {
        _entriesList->push_back(ListEntry(rawFilename.c_str(), []{;}));
    }
}

void LibraryViewController::init(std::function<void(Views)> requestViewImpl)
{
    _requestView = requestViewImpl;
}

void LibraryViewController::draw()
{
    this->_screenService->clearScreen();
    this->_screenService->displayScrollableList(_entriesList);
    refreshCursor();
}
