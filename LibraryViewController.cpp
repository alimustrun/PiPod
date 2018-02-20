//
// Created by fritsch on 16/02/18.
//

#include "LibraryViewController.h"
#include "ButtonsGPIO.h"
#include "Utils.h"

LibraryViewController::LibraryViewController(ScreenService *screenService)
{
    this->_screenService = screenService;
    this->_currentSelection = 0;
    this->_entriesList = new std::vector<ListEntry>;
    this->initEntriesList();
    this->_screenService->displayScrollableList(_entriesList);
    refreshCursor();
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
    std::vector<const char *> rawFilenames = std::vector<const char *>();
    Utils::getFilesFromPath(&rawFilenames, "~/");
    for (auto *rawFilename : rawFilenames)
    {
        _entriesList->push_back(ListEntry(rawFilename, []{;}));
    }
}

void LibraryViewController::init(std::function<void(Views)> requestViewImpl)
{

}
