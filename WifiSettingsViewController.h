//
// Created by fritsch on 19/02/18.
//

#ifndef PIPOD_WIFISETTINGSVIEWCONTROLLER_H
#define PIPOD_WIFISETTINGSVIEWCONTROLLER_H


#include <functional>
#include "ViewController.h"

class WifiSettingsViewController : public ViewController
{
public:
    void init(std::function<void(Views)> requestViewImpl) override;
    const void onKeyPressed(int key) override;
};


#endif //PIPOD_WIFISETTINGSVIEWCONTROLLER_H
