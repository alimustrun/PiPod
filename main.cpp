#include <iostream>
#include <gtest/gtest.h>
#include "KeyboardService.h"
#include "ScreenService.h"
#include "MainViewController.h"

int main(int argc, char **argv) {
    if (argc > 1)
    {
        ::testing::InitGoogleTest(&argc, argv);
        RUN_ALL_TESTS();
    }
    auto *keyboardService = new KeyboardService();
    auto *screenService = new ScreenService();
    screenService->start();
    keyboardService->start();

    auto *mainViewController = new MainViewController(screenService);

    keyboardService->addListener(std::bind(&ScreenService::onKeyPressed, screenService, std::placeholders::_1));
    keyboardService->addListener(std::bind(&MainViewController::onKeyPressed, mainViewController, std::placeholders::_1));
    while (true)
    {
      keyboardService->refreshKeys();
      usleep(20000);
    }
    return 0;
}
