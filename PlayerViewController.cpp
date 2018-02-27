//
// Created by fritsch on 19/02/18.
//

#include "PlayerViewController.h"
#include "ButtonsGPIO.h"

void PlayerViewController::init(std::function<void(Views)> requestViewImpl)
{
    _requestView = requestViewImpl;
}

const void PlayerViewController::onKeyPressed(int key)
{
    switch (key)
    {
        case VOL_DEC:
            break;
        case VOL_INC:
            break;
        case PREV:
            break;
        case NEXT:
            break;
        case RIGHT:
            _requestView(Views::MAIN_MENU);
            break;
        case CENTER:
            break;
        case LEFT:
            break;
        default:
            break;
    }
}

void PlayerViewController::draw()
{

}

PlayerViewController::PlayerViewController(ScreenService *screenService, MusicService *musicService)
{
    _screenService = screenService;
    _musicService = musicService;
}
