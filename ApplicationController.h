//
// Created by fritsch on 19/02/18.
//

#ifndef PIPOD_APPLICATIONCONTROLLER_H
#define PIPOD_APPLICATIONCONTROLLER_H

#include "ScreenService.h"
#include "MainViewController.h"
#include "LibraryViewController.h"
#include "KeyboardService.h"
#include "PlayerViewController.h"
#include "WifiSettingsViewController.h"
#include "LibraryUpdateViewController.h"
#include "Views.h"

class ApplicationController
{
public:
    ApplicationController();
    void requestView(Views requestedView);
    void onKeyPressed(int key);
private:

    std::map<Views, ViewController *> *_viewControllers;
    ScreenService *_screenService;
    KeyboardService *_keyboardService;
    Views _currentView;

    void initViewControllers();

    MainViewController *createMainViewController();
};


#endif //PIPOD_APPLICATIONCONTROLLER_H
