#include <iostream>
#include <gtest/gtest.h>
#include "KeyboardService.h"
#include "ScreenService.h"
#include "MainViewController.h"
#include "ApplicationController.h"

int main(int argc, char **argv) {
    if (argc > 1)
    {
        ::testing::InitGoogleTest(&argc, argv);
        RUN_ALL_TESTS();
    }
    auto *applicationController = new ApplicationController();
    return 0;
}
