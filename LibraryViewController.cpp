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
    std::cout << "aa" << std::endl;
    this->_currentSelection = 0;
    std::cout << "ab" << std::endl;
    this->_entriesList = new std::vector<ListEntry>;
    std::cout << "ac" << std::endl;
    this->initEntriesList();
    std::cout << "ad" << std::endl;
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
    auto *rawFilenames = new std::vector<const char *>;
    std::cout << "af" << std::endl;
    Utils::getFilesFromPath(rawFilenames, "/home/pi/");
    std::cout << "ag" << std::endl;
    for (auto rawFilename : *rawFilenames)
    {
        _entriesList->push_back(ListEntry(asciify(rawFilename), []{;}));
    }
    std::cout << "ah" << std::endl;
}

const char *LibraryViewController::asciify(const char *rawString)
{
    size_t rawStringLength = strlen(rawString);
    auto *output = static_cast<char *>(malloc(sizeof(char) * 32));
    size_t j = 0;
    for (size_t i = 0; i < rawStringLength && j < 32 - 1; ++i)
    {
        if (rawString[i] < 128 && rawString[i] > 0)
        {
            output[j] = rawString[i];
            ++j;
        }
    }
    output[j] = '\0';
    std::cout << "input : " << rawString << ", output : " << output << std::endl;
    return output;
}

void LibraryViewController::init(std::function<void(Views)> requestViewImpl)
{
    _requestView = requestViewImpl;
    this->_screenService->clearScreen();
    this->_screenService->displayScrollableList(_entriesList);
    std::cout << "ae" << std::endl;
    refreshCursor();
}
