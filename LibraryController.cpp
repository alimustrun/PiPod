//
// Created by fritsch on 16/02/18.
//

#include "LibraryController.h"
#include "ButtonsGPIO.h"

LibraryController::LibraryController(ScreenService *screenService)
{
    this->_screenService = screenService;
    this->_currentSelection = 0;
    this->_entriesList = new std::vector<ListEntry>;
    this->initEntriesList();
    this->_screenService->displayScrollableList(_entriesList);
    refreshCursor();
}

const void LibraryController::onKeyPressed(int key)
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

void LibraryController::refreshCursor()
{
    this->_screenService->displayCursor(this->_currentSelection, _entriesList);
}

void LibraryController::initEntriesList()
{
    //here list directories
//    const std::function<void(void)> tenthCallback = []{/* launch tenth screen */ printf("tenth clicked\n");};
//    _entriesList->push_back(ListEntry("tenth", tenthCallback));
}
