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
}

const void MainViewController::onKeyPressed(int key)
{
    switch (key)
    {
        case VOL_DEC:
            //move cursor down
            break;
        case VOL_INC:
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