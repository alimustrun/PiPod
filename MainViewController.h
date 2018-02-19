//
// Created by fritsch on 16/02/18.
//

#ifndef PIPOD_MAINVIEWCONTROLLER_H
#define PIPOD_MAINVIEWCONTROLLER_H


#include <vector>
#include "ScreenService.h"
#include "ListEntry.h"
#include "ViewController.h"

class MainViewController : ViewController
{
public:
    explicit MainViewController(ScreenService *screenService);
    const void onKeyPressed(int) override;
    void init(std::function<void(Views)> requestViewImpl) override;

private:
    void refreshCursor();
    void initEntriesList();

    ScreenService *_screenService;
    unsigned long _currentSelection;
    std::vector<ListEntry> *_entriesList;
};


#endif //PIPOD_MAINVIEWCONTROLLER_H
