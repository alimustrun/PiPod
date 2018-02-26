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
    this->_currentDirectoryLevel = 0;
    this->_currentPath = "/home/pi/Music/";
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
            _currentDirectoryLevel--;
            if (_currentDirectoryLevel == 0)
            {
                _requestView(Views::MAIN_MENU);
            }
            break;
        case NEXT:
            std::cout << "next 1:" << _currentSelection << ", entries.size:" << _entriesList->size() << std::endl;
            _entriesList->at(_currentSelection).executeAction();
            std::cout << "next 2" << std::endl;
            _currentDirectoryLevel++;
            std::cout << "next 3" << std::endl;
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
    fetchCurrentPathFiles();
}

void LibraryViewController::fetchCurrentPathFiles()
{
    std::cout << "fetchCurrentPathFiles 1" << std::endl;
    auto *rawFilenames = new std::vector<std::string>;
    Utils::getFilesFromPath(rawFilenames, _currentPath.c_str());
    std::cout << "fetchCurrentPathFiles 2" << std::endl;
    for (const auto &rawFilename : *rawFilenames)
    {
        std::cout << "fetchCurrentPathFiles 3" << std::endl;
        _entriesList->push_back(ListEntry(new std::string(rawFilename),
                                          [&]{
                                                std::cout << "one" << std::endl;
                                              auto *realPath = static_cast<char *>(malloc(sizeof(char) * 1024));
                                              std::cout << "two:" << _currentPath << std::endl;
                                              realpath(_currentPath.append(rawFilename).append("/").c_str(), realPath);
                                              std::cout << "three" << std::endl;
                                              std::cout << realPath << std::endl;
                                              std::cout << "four" << std::endl;
                                              _currentPath = realPath;
                                              std::cout << "five" << std::endl;
                                              fetchCurrentPathFiles();
                                              std::cout << "six" << std::endl;
                                              draw();
                                              std::cout << "seven" << std::endl;

                                          }
        ));
        std::cout << "fetchCurrentPathFiles 4" << std::endl;
    }
}

void LibraryViewController::init(std::function<void(Views)> requestViewImpl)
{
    _requestView = requestViewImpl;
}

void LibraryViewController::draw()
{
    std::cout << "draw 1" << std::endl;
    this->_screenService->clearScreen();
    std::cout << "draw 2" << std::endl;
    this->_screenService->displayScrollableList(_entriesList);
    std::cout << "draw 3" << std::endl;
    refreshCursor();
    std::cout << "draw 4" << std::endl;
}
