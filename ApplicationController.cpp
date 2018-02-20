//
// Created by fritsch on 19/02/18.
//

#include <unistd.h>
#include <iostream>
#include "ApplicationController.h"

void ApplicationController::requestView(Views requestedView)
{
    _currentView = requestedView;
    //TODO:  show requested view
}

void ApplicationController::initViewControllers()
{
    _viewControllers = new std::map<Views, ViewController *>;
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::MAIN_MENU, createMainViewController()));
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::LIBRARY, new LibraryViewController(_screenService)));
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::PLAYER, new PlayerViewController()));
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::WIFI_SETTINGS, new WifiSettingsViewController()));
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::LIBRARY_UPDATE, new LibraryUpdateViewController()));
}

MainViewController *ApplicationController::createMainViewController()
{
    auto *mainViewController = new MainViewController(_screenService);
    mainViewController->init(std::bind(&ApplicationController::requestView, this, std::placeholders::_1));
    return mainViewController;
}

ApplicationController::ApplicationController()
{
    std::cout << "1" << std::endl;
    _keyboardService = new KeyboardService();
    std::cout << "2" << std::endl;
    _screenService = new ScreenService();
    std::cout << "3" << std::endl;
    _screenService->start();
    std::cout << "4" << std::endl;
    _keyboardService->start();
    std::cout << "5" << std::endl;

    initViewControllers();
    std::cout << "6" << std::endl;
    _keyboardService->addListener(std::bind(&ApplicationController::onKeyPressed, this, std::placeholders::_1));
    std::cout << "7" << std::endl;

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
