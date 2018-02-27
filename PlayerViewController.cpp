//
// Created by fritsch on 19/02/18.
//

#include "PlayerViewController.h"

void PlayerViewController::init(std::function<void(Views)> requestViewImpl)
{
    _requestView = requestViewImpl;
}

const void PlayerViewController::onKeyPressed(int key)
{
    return;
}

void PlayerViewController::draw()
{

}

PlayerViewController::PlayerViewController(ScreenService *screenService, MusicService *musicService)
{
    _screenService = screenService;
    _musicService = musicService;
}
