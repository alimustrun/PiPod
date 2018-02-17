//
// Created by fritsch on 16/02/18.
//

#include "MainViewController.h"
#include "ButtonsGPIO.h"

MainViewController::MainViewController(ScreenService *screenService)
{
    this->_screenService = screenService;
    //this->_screenService->displayBootScreen();
    //sleep(1);
    this->_currentSelection = 0;
    this->_entriesList = new std::vector<ListEntry>;
    this->initEntriesList();
    this->_screenService->displayMainScreen(_entriesList);
    refreshCursor();
}

const void MainViewController::onKeyPressed(int key)
{
    switch (key)
    {
        case VOL_DEC:
            this->_currentSelection = this->_currentSelection > 0 ? this->_currentSelection - 1 : 0;
            refreshCursor();
            //move cursor down
            break;
        case VOL_INC:
            this->_currentSelection = this->_currentSelection < _entriesList->size() - 1 ? this->_currentSelection + 1 : this->_currentSelection;
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
    this->_screenService->displayCursor(this->_currentSelection, _entriesList->size());
}

void MainViewController::initEntriesList()
{
    const std::function<void(void)> premierCallback = []{/* launch premier screen */ printf("premier clicked\n");};
    _entriesList->push_back(ListEntry("Premier", premierCallback));
    const std::function<void(void)> secondCallback = []{/* launch second screen */ printf("second clicked\n");};
    _entriesList->push_back(ListEntry("Second", secondCallback));
    const std::function<void(void)> thirdCallback = []{/* launch third screen */ printf("third clicked\n");};
    _entriesList->push_back(ListEntry("Third", thirdCallback));
    const std::function<void(void)> fourthCallback = []{/* launch fourth screen */ printf("fourth clicked\n");};
    _entriesList->push_back(ListEntry("Fourth", fourthCallback));
    const std::function<void(void)> fifthCallback = []{/* launch fifth screen */ printf("fifth clicked\n");};
    _entriesList->push_back(ListEntry("Fifth", fifthCallback));
    const std::function<void(void)> sixthCallback = []{/* launch sixth screen */ printf("sixth clicked\n");};
    _entriesList->push_back(ListEntry("Sixth", sixthCallback));
    const std::function<void(void)> seventhCallback = []{/* launch seventh screen */ printf("seventh clicked\n");};
    _entriesList->push_back(ListEntry("Seventh", seventhCallback));
}
