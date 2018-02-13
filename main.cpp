#include <iostream>
#include <gtest/gtest.h>
#include "screen-driver/ScreenDriver.h"
#include "Number.h"

int main(int argc, char **argv) {
//    ScreenDriver *screenDriver = new ScreenDriver();
//    screenDriver->displaySomething();
   // Number *number = new Number();
   // std::cout << number->isOdd(1) << std::flush;
    ::testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    return 0;
}