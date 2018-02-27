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
    this->_currentDirectoryLevel = 3;
    this->_currentPath = new std::string("/home/pi/Music/");
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
            _currentSelection = 0;
            if (_currentDirectoryLevel == 0)
            {
                _requestView(Views::MAIN_MENU);
            }
            else
            {
                this->changeDirectory("..");
                fetchCurrentPathFiles();
                this->draw();
            }
            break;
        case NEXT:
            _entriesList->at(_currentSelection).executeAction();
            _currentDirectoryLevel++;
            _currentSelection = 0;
            fetchCurrentPathFiles();
            this->draw();
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
    this->_screenService->displayCursor(this->_currentSelection, _entriesList, false);
}

void LibraryViewController::initEntriesList()
{
    fetchCurrentPathFiles();
}

void LibraryViewController::fetchCurrentPathFiles()
{
    auto *filenames = new std::vector<std::pair<std::string, FileType>>;
    Utils::getFilesFromPath(filenames, _currentPath->c_str());
    _entriesList->clear();
    for (const auto &filename : *filenames)
    {
        _entriesList->push_back(ListEntry(new std::string(filename.first),
                                          filename.second,
                                          [&]{
                                              if (filename.second == FileType::TYPE_DIRECTORY)
                                              {
                                                  this->changeDirectory(filename.first.c_str());
                                              }
                                              else if (filename.second == FileType::TYPE_FILE)
                                              {
                                                  std::cout << "should play " << filename.first << std::endl;
                                                  //TODO : open player with the file
                                              }
                                          }
        ));
    }
}

void LibraryViewController::changeDirectory(const char *newDirectory)
{
    _currentPath = Utils::changeDirectory(_currentPath->c_str(), newDirectory);
    std::cout << "Going to : " << _currentPath->c_str() << std::endl;
}

void LibraryViewController::init(std::function<void(Views)> requestViewImpl)
{
    _requestView = requestViewImpl;
}

void LibraryViewController::draw()
{
    this->_screenService->fullClear();
    this->_screenService->displayScrollableList(_entriesList);
    refreshCursor();
}
