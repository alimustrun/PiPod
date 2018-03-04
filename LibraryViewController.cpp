//
// Created by fritsch on 16/02/18.
//

#include <iostream>
#include <algorithm>
#include <cstring>
#include "LibraryViewController.h"
#include "ButtonsGPIO.h"
#include "Utils.h"

LibraryViewController::LibraryViewController(ScreenService *screenService, MusicService *musicService)
{
    this->_screenService = screenService;
    this->_musicService = musicService;
    this->_currentSelection = 0;
    this->_currentDirectoryLevel = 0;
    this->_currentPath = new std::string("/home/pi/Music/");
    this->_entriesList = new std::vector<ListEntry>;
    this->initEntriesList();
}

const void LibraryViewController::onKeyPressed(int key)
{
    switch (key)
    {
        case VOL_DEC:
            this->_currentSelection = this->_currentSelection < _entriesList->size() - 1 ? this->_currentSelection + 1
                                                                                         : this->_currentSelection;
            refreshCursor(false);
            break;
        case VOL_INC:
            this->_currentSelection = this->_currentSelection > 0 ? this->_currentSelection - 1 : 0;
            refreshCursor(false);
            break;
        case PREV:
            _currentSelection = 0;
            if (_currentDirectoryLevel == 0)
            {
                _requestView(View::MAIN_MENU);
            }
            else
            {
                _currentDirectoryLevel--;
                this->changeDirectory("..");
            }
            break;
        case NEXT:
            _entriesList->at(_currentSelection).executeAction();
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

void LibraryViewController::refreshCursor(bool fullDisplayRefresh)
{
    this->_screenService->displayCursor(this->_currentSelection, _entriesList, fullDisplayRefresh);
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
                                          [&]
                                          {
                                              if (filename.second == FileType::TYPE_DIRECTORY)
                                              {
                                                  this->_currentDirectoryLevel++;
                                                  this->_currentSelection = 0;
                                                  this->changeDirectory(filename.first.c_str());
                                              }
                                              else if (filename.second == FileType::TYPE_FILE)
                                              {
                                                  std::string temporaryPath = std::string(_currentPath->c_str()).append(
                                                          "/").append(filename.first);
                                                  _musicService->playMusicAtGivenPath(temporaryPath.c_str());
                                                  _requestView(View::PLAYER);
                                              }
                                          }
                                         ));
    }
}

void LibraryViewController::changeDirectory(const char *newDirectory)
{
    _currentPath = Utils::changeDirectory(_currentPath->c_str(), newDirectory);
    this->fetchCurrentPathFiles();
    this->draw();
}

void LibraryViewController::init(std::function<void(View)> requestViewImpl)
{
    _requestView = requestViewImpl;
}

void LibraryViewController::draw()
{
    this->_screenService->displayScrollableList(_entriesList);
}
