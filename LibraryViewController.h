//
// Created by fritsch on 16/02/18.
//

#ifndef PIPOD_LIBRARYVIEWCONTROLLER_H
#define PIPOD_LIBRARYVIEWCONTROLLER_H


#include <vector>
#include <dirent.h>
#include "ScreenService.h"
#include "ListEntry.h"
#include "ViewController.h"

class LibraryViewController : public ViewController
{
public:
    void init(std::function<void(Views)> requestViewImpl) override;
    void draw() override;
    explicit LibraryViewController(ScreenService *screenService);
    const void onKeyPressed(int);

private:
    ScreenService *_screenService;
    unsigned long _currentSelection;
    std::vector<ListEntry> *_entriesList;
    std::string *_currentPath;
    int _currentDirectoryLevel;

    void refreshCursor(bool fullScreenRefresh);
    void initEntriesList();
    void fetchCurrentPathFiles();

    void changeDirectory(const char *newDirectory);
};


#endif //PIPOD_LIBRARYVIEWCONTROLLER_H
