//
// Created by fritsch on 19/02/18.
//

#ifndef PIPOD_PLAYERVIEWCONTROLLER_H
#define PIPOD_PLAYERVIEWCONTROLLER_H


#include <functional>
#include "ViewController.h"
#include "ScreenService.h"
#include "MusicService.h"

class PlayerViewController : public ViewController
{
public:
    PlayerViewController(ScreenService *screenService, MusicService *musicService);
    void init(std::function<void(View)> requestViewImpl) override;
    void draw() override;
    const void onKeyPressed(int key) override;

private:
    ScreenService *_screenService;
    MusicService *_musicService;
};


#endif //PIPOD_PLAYERVIEWCONTROLLER_H
