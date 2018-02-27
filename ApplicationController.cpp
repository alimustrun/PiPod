//
// Created by fritsch on 19/02/18.
//

#include <unistd.h>
#include <iostream>
#include "ApplicationController.h"

void ApplicationController::requestView(Views requestedView)
{
    _currentView = requestedView;
    _viewControllers->at(requestedView)->draw();
}

void ApplicationController::initViewControllers()
{
    _viewControllers = new std::map<Views, ViewController *>;
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::MAIN_MENU, createMainViewController()));
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::LIBRARY, createLibraryViewController()));
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::PLAYER, createPlayerViewController()));
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::WIFI_SETTINGS, new WifiSettingsViewController()));
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::LIBRARY_UPDATE, new LibraryUpdateViewController()));
}

MainViewController *ApplicationController::createMainViewController()
{
    auto *mainViewController = new MainViewController(_screenService);
    mainViewController->init(std::bind(&ApplicationController::requestView, this, std::placeholders::_1));
    return mainViewController;
}

LibraryViewController *ApplicationController::createLibraryViewController()
{
    auto *libraryViewController = new LibraryViewController(_screenService, _musicService);
    libraryViewController->init(std::bind(&ApplicationController::requestView, this, std::placeholders::_1));
    return libraryViewController;
}

PlayerViewController *ApplicationController::createPlayerViewController()
{
    auto *playerViewController = new PlayerViewController(_screenService, _musicService);
    playerViewController->init(std::bind(&ApplicationController::requestView, this, std::placeholders::_1));
    return playerViewController;
}

ApplicationController::ApplicationController()
{
    _keyboardService = new KeyboardService();
    _screenService = new ScreenService();
    _musicService = new MusicService();
    _screenService->start();
    _screenService->fullClear();
    _keyboardService->start();
    _musicService->start();

    initViewControllers();
    requestView(Views::MAIN_MENU);
    _keyboardService->addListener(std::bind(&ApplicationController::onKeyPressed, this, std::placeholders::_1));

    while (true)
    {
        _keyboardService->refreshKeys();
        usleep(20000);
    }
}

void ApplicationController::onKeyPressed(int key)
{
    _viewControllers->at(_currentView)->onKeyPressed(key);
}

