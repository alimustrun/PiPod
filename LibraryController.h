//
// Created by fritsch on 16/02/18.
//

#ifndef PIPOD_LIBRARYCONTROLLER_H
#define PIPOD_LIBRARYCONTROLLER_H


#include <vector>
#include "ScreenService.h"
#include "ListEntry.h"

class LibraryController
{
public:
    explicit LibraryController(ScreenService *screenService);
    const void onKeyPressed(int);

private:
    ScreenService *_screenService;
    unsigned long _currentSelection;
    std::vector<ListEntry> *_entriesList;

    void refreshCursor();
    void initEntriesList();
};


#endif //PIPOD_LIBRARYCONTROLLER_H
