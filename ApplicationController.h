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
#include "View.h"
#include "MusicService.h"

class ApplicationController
{
public:
    ApplicationController();
    void requestView(View requestedView);
    void onKeyPressed(int key);
private:

    std::map<View, ViewController *> *_viewControllers;
    ScreenService *_screenService;
    KeyboardService *_keyboardService;
    MusicService *_musicService;
    View _currentView;

    void initViewControllers();

    MainViewController *createMainViewController();
    LibraryViewController *createLibraryViewController();
    PlayerViewController *createPlayerViewController();
};


#endif //PIPOD_APPLICATIONCONTROLLER_H
