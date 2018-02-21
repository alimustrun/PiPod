//
// Created by fritsch on 19/02/18.
//

#include <unistd.h>
#include <iostream>
#include "ApplicationController.h"

void ApplicationController::requestView(Views requestedView)
{
    _currentView = requestedView;
    std::cout << "view loaded" << std::endl;
    _viewControllers->at(requestedView)->init(std::bind(&ApplicationController::requestView, this, std::placeholders::_1));
}

void ApplicationController::initViewControllers()
{
    _viewControllers = new std::map<Views, ViewController *>;
    std::cout << "a" << std::endl;
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::MAIN_MENU, createMainViewController()));
    std::cout << "b" << std::endl;
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::LIBRARY, new LibraryViewController(_screenService)));
    std::cout << "c" << std::endl;
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::PLAYER, new PlayerViewController()));
    std::cout << "d" << std::endl;
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::WIFI_SETTINGS, new WifiSettingsViewController()));
    std::cout << "e" << std::endl;
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::LIBRARY_UPDATE, new LibraryUpdateViewController()));
}

MainViewController *ApplicationController::createMainViewController()
{
    auto *mainViewController = new MainViewController(_screenService);
    std::cout << "*" << std::endl;
    mainViewController->init(std::bind(&ApplicationController::requestView, this, std::placeholders::_1));
    std::cout << "+" << std::endl;
    return mainViewController;
}

ApplicationController::ApplicationController()
{
    _keyboardService = new KeyboardService();
    _screenService = new ScreenService();
    _screenService->start();
    _keyboardService->start();

    initViewControllers();
    _currentView = Views::MAIN_MENU;
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
