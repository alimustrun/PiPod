//
// Created by fritsch on 19/02/18.
//

#ifndef PIPOD_LIBRARYUPDATEVIEWCONTROLLER_H
#define PIPOD_LIBRARYUPDATEVIEWCONTROLLER_H


#include <functional>
#include "ViewController.h"

class LibraryUpdateViewController : public ViewController
{
public:
    void init(std::function<void(Views)> requestViewImpl) override;

    const void onKeyPressed(int key) override;
};


#endif //PIPOD_LIBRARYUPDATEVIEWCONTROLLER_H
