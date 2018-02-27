//
// Created by fritsch on 16/02/18.
//

#include <unistd.h>

#include <utility>
#include <iostream>
#include "MainViewController.h"
#include "ButtonsGPIO.h"
#include "LibraryViewController.h"

MainViewController::MainViewController(ScreenService *screenService)
{
    this->_screenService = screenService;
    this->_screenService->displayBootScreen();
    sleep(3);
    this->_currentSelection = 0;
    this->_entriesList = new std::vector<ListEntry>;
    this->initEntriesList();
}

const void MainViewController::onKeyPressed(int key)
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
            std::cout << "execution action for " << _currentSelection << std::endl;
            _entriesList->at(_currentSelection).executeAction();
            //select menu
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

void MainViewController::refreshCursor()
{
    this->_screenService->displayCursor(this->_currentSelection, _entriesList, false);
}

void MainViewController::initEntriesList()
{
    _entriesList->push_back(ListEntry(new std::string("Library"),
                                      FileType::TYPE_NA,
                                      [&]{requestLibraryView();}));
    _entriesList->push_back(ListEntry(new std::string("ROM update"),
                                      FileType::TYPE_NA,
                                      []{printf("Mise a jour du logiciel clicked\n");}));
    _entriesList->push_back(ListEntry(new std::string("Library update"),
                                      FileType::TYPE_NA,
                                      []{printf("Mise a jour de la bibliotheque clicked\n");}));
    _entriesList->push_back(ListEntry(new std::string("Wi-Fi settings"),
                                      FileType::TYPE_NA,
                                      []{printf("Parametres Wi-Fi clicked\n");}));
}

void MainViewController::requestView(Views view)
{
    _requestView(view);
}

void MainViewController::requestLibraryView()
{
    requestView(Views::LIBRARY);
}

void MainViewController::init(std::function<void(Views)> requestViewImpl)
{
    _requestView = requestViewImpl;
}

void MainViewController::draw()
{
    this->_screenService->quickClear();
    this->_screenService->displayScrollableList(_entriesList);
    refreshCursor();
}
