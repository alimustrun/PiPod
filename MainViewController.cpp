//
// Created by fritsch on 16/02/18.
//

#include <unistd.h>
#include "MainViewController.h"
#include "ButtonsGPIO.h"

MainViewController::MainViewController(ScreenService *screenService)
{
    this->_screenService = screenService;
    this->_screenService->displayBootScreen();
    sleep(3);
    this->_currentSelection = 0;
    this->_entriesList = new std::vector<ListEntry>;
    this->initEntriesList();
    this->_screenService->displayScrollableList(_entriesList);
    refreshCursor();
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
    this->_screenService->displayCursor(this->_currentSelection, _entriesList);
}

void MainViewController::initEntriesList()
{
    _entriesList->push_back(ListEntry("Bibliothèque", []{/* open library */ printf("premier clicked\n");}));
    _entriesList->push_back(ListEntry("Second", []{/* launch second screen */ printf("second clicked\n");}));
    _entriesList->push_back(ListEntry("Third", []{/* launch third screen */ printf("third clicked\n");}));
    _entriesList->push_back(ListEntry("Fourth", []{/* launch fourth screen */ printf("fourth clicked\n");}));
    _entriesList->push_back(ListEntry("Fifth", []{/* launch fifth screen */ printf("fifth clicked\n");}));
    _entriesList->push_back(ListEntry("Sixth", []{/* launch sixth screen */ printf("sixth clicked\n");}));
    _entriesList->push_back(ListEntry("Seventh", []{/* launch seventh screen */ printf("seventh clicked\n");}));
    _entriesList->push_back(ListEntry("eight", []{/* launch eight screen */ printf("eight clicked\n");}));
    _entriesList->push_back(ListEntry("ninth", []{/* launch ninth screen */ printf("ninth clicked\n");}));
    _entriesList->push_back(ListEntry("tenth", []{/* launch tenth screen */ printf("tenth clicked\n");}));
}
