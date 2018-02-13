#include <iostream>
#include <gtest/gtest.h>
#include "screen-driver/ScreenDriver.h"
#include "Number.h"
#include "KeyboardService.h"

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
    while (true)
    {
        keyboardService->refreshKeys();
        keyboardService->printKeysStatuses();
        sleep(1);
    }
    return 0;
}