//
// Created by fritsch on 16/02/18.
//

#ifndef PIPOD_MAINVIEWCONTROLLER_H
#define PIPOD_MAINVIEWCONTROLLER_H


#include "ScreenService.h"

class MainViewController
{
public:
    explicit MainViewController(ScreenService *screenService);

    const void onKeyPressed(int);

private:
    ScreenService *_screenService;
};


#endif //PIPOD_MAINVIEWCONTROLLER_H
