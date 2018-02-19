//
// Created by fritsch on 16/02/18.
//

#ifndef PIPOD_LIBRARYVIEWCONTROLLER_H
#define PIPOD_LIBRARYVIEWCONTROLLER_H


#include <vector>
#include "ScreenService.h"
#include "ListEntry.h"
#include "ViewController.h"

class LibraryViewController : ViewController
{
public:
    explicit LibraryViewController(ScreenService *screenService);
    const void onKeyPressed(int);

private:
    ScreenService *_screenService;
    unsigned long _currentSelection;
    std::vector<ListEntry> *_entriesList;

    void refreshCursor();
    void initEntriesList();
};


#endif //PIPOD_LIBRARYVIEWCONTROLLER_H
