#include <iostream>
#include <gtest/gtest.h>
#include "screen-driver/ScreenDriver.h"
#include "Number.h"
#include "KeyboardService.h"
#include "ScreenService.h"

int main(int argc, char **argv) {
//    ScreenDriver *screenDriver = new ScreenDriver();
//    screenDriver->displaySomething();
   // Number *number = new Number();
   // std::cout << number->isOdd(1) << std::flush;
    if (argc > 1)
    {
        ::testing::InitGoogleTest(&argc, argv);
        RUN_ALL_TESTS();
    }
    auto *keyboardService = new KeyboardService();
    keyboardService->start();
    auto *screenService = new ScreenService();
    keyboardService->addListener(std::bind(&ScreenService::onKeyPressed, screenService, std::placeholders::_1));
    while (true)
    {
      keyboardService->refreshKeys();
      sleep(1);
    }
    return 0;
}
