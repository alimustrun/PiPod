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
    _currentView = Views::MAIN_MENU;
    _keyboardService->addListener(std::bind(&ApplicationController::onKeyPressed, this, std::placeholders::_1));
    std::cout << "7" << std::endl;

    while (true)
    {
        std::cout << "refresh keys" << std::endl;
        _keyboardService->refreshKeys();
        usleep(200000);
    }
}

void ApplicationController::onKeyPressed(int key)
{
    _viewControllers->at(_currentView)->onKeyPressed(key);
}
