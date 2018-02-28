//
// Created by fritsch on 19/02/18.
//

#include <iostream>
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
            _musicService->decreaseVolumeClicked();
            break;
        case VOL_INC:
            _musicService->increaseVolumeClicked();
            break;
        case PREV:
            _musicService->playPreviousSongClicked();
            break;
        case NEXT:
            _musicService->playNextSongClicked();
            break;
        case RIGHT:
            _requestView(Views::MAIN_MENU);
            break;
        case CENTER:
            break;
        case LEFT:
            _musicService->playClicked();
            break;
        default:
            break;
    }
}

void PlayerViewController::draw()
{
    this->_screenService->quickClear();
    this->_screenService->drawPlayer(_musicService->getPlayingMusic());
    this->_screenService->requestDisplay();
}

PlayerViewController::PlayerViewController(ScreenService *screenService, MusicService *musicService)
{
    _screenService = screenService;
    _musicService = musicService;
}
