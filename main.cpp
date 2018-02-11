#include "screen-driver/ScreenDriver.h"

int main() {
    ScreenDriver *screenDriver = new ScreenDriver();
    screenDriver->displaySomething();
    return 0;
}