//
// Created by fritsch on 16/02/18.
//

#include <zconf.h>
#include "MainViewController.h"
#include "ButtonsGPIO.h"

MainViewController::MainViewController(ScreenService *screenService)
{
    this->_screenService = screenService;
    this->_screenService->displayBootScreen();
    sleep(1);
    this->_screenService->displayMainScreen();
    this->_currentSelection = 1;
    refreshCursor();
}

const void MainViewController::onKeyPressed(int key)
{
    switch (key)
    {
        case VOL_DEC:
            this->_currentSelection = this->_currentSelection > 1 ? this->_currentSelection - 1 : 1;
            refreshCursor();
            //move cursor down
            break;
        case VOL_INC:
            this->_currentSelection = this->_currentSelection < 4/* nb_items */ ? this->_currentSelection + 1 : this->_currentSelection;
            refreshCursor();
            //move cursor up
            break;
        case PREV:
            break;
        case NEXT:
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
    this->_screenService->displayCursor(this->_currentSelection);
}
