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
#include "MusicService.h"

class LibraryViewController : public ViewController
{
public:
    explicit LibraryViewController(ScreenService *screenService, MusicService *musicService);
    void init(std::function<void(View)> requestViewImpl) override;
    void draw() override;
    const void onKeyPressed(int) override;

private:
    ScreenService *_screenService;
    MusicService *_musicService;
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
