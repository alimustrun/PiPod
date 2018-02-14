#include <iostream>
#include <gtest/gtest.h>
#include "KeyboardService.h"
#include "ScreenService.h"

int main(int argc, char **argv) {
    if (argc > 1)
    {
        ::testing::InitGoogleTest(&argc, argv);
        RUN_ALL_TESTS();
    }
    auto *keyboardService = new KeyboardService();
    keyboardService->start();
    auto *screenService = new ScreenService();
    screenService->start();
    keyboardService->addListener(std::bind(&ScreenService::onKeyPressed, screenService, std::placeholders::_1));
    while (true)
    {
      keyboardService->refreshKeys();
      usleep(20000);
    }
    return 0;
}
