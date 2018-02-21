//
// Created by fritsch on 19/02/18.
//

#ifndef PIPOD_PLAYERVIEWCONTROLLER_H
#define PIPOD_PLAYERVIEWCONTROLLER_H


#include <functional>
#include "ViewController.h"

class PlayerViewController : public ViewController
{
public:
    void init(std::function<void(Views)> requestViewImpl) override;
    void draw() override;
    const void onKeyPressed(int key) override;
};


#endif //PIPOD_PLAYERVIEWCONTROLLER_H
