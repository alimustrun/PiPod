//
// Created by fritsch on 19/02/18.
//

#ifndef PIPOD_VIEWCONTROLLER_H
#define PIPOD_VIEWCONTROLLER_H

#include "View.h"

class ViewController
{
public:
    virtual void init(std::function<void(View)> requestViewImpl) = 0;

    virtual void draw() = 0;

    virtual const void onKeyPressed(int key) = 0;

protected:
    std::function<void(View)> _requestView;
};


#endif //PIPOD_VIEWCONTROLLER_H
