//
// Created by fritsch on 19/02/18.
//

#include <unistd.h>
#include "ApplicationController.h"

void ApplicationController::requestView(Views requestedView)
{
    _currentView = requestedView;
    //TODO:  show requested view
}

void ApplicationController::initViewControllers()
{
    _viewControllers = new std::map<Views, ViewController *>;
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::MAIN_MENU, new MainViewController(_screenService)));
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::LIBRARY, new LibraryViewController(_screenService)));
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::PLAYER, new PlayerViewController()));
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::WIFI_SETTINGS, new WifiSettingsViewController()));
    _viewControllers->insert(std::pair<Views, ViewController *>(Views::LIBRARY_UPDATE, new LibraryUpdateViewController()));
}

void ApplicationController::initMainViewController()
{

}

ApplicationController::ApplicationController()
{
    _keyboardService = new KeyboardService();
    _screenService = new ScreenService();
    _screenService->start();
    _keyboardService->start();

    initViewControllers();
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
