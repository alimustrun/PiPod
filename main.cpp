
#include <gtest/gtest.h>
#include "ApplicationController.h"

int main(int argc, char **argv) {
    if (argc > 1)
    {
        ::testing::InitGoogleTest(&argc, argv);
        RUN_ALL_TESTS();
    }
    new ApplicationController();
    return 0;
}
