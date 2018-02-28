#include <iostream>
#include <cstring>
#include "ScreenDriver.h"
#include "../MusicFile.h"

ScreenDriver::ScreenDriver()
{
    _epd = new Epd();
    if (_epd->Init(lut_partial_update) != 0)
    {
        printf("e-Paper init failed\n");
        return;
    }
    _frame_buffer = (unsigned char*)malloc(_epd->width / 8 * _epd->height);
    _paint = new Paint(_frame_buffer, _epd->width, _epd->height);
    _paint->SetRotate(ROTATE_90);
    fullClear();
}


const void ScreenDriver::fullClear()
{
    _paint->SetWidth(_epd->width);
    _paint->SetHeight(_epd->height);
    _paint->Clear(UNCOLORED);
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    _epd->DisplayFrame();
    _paint->Clear(COLORED);
    this->displayFrame();
}

const void ScreenDriver::displayBootScreen()
{
    _paint->SetWidth(30);
    _paint->SetHeight(255);
    _paint->Clear(COLORED);
    _paint->DrawStringAt(0, 0, "PiPod", &Font24, UNCOLORED);
    this->displayFrame();
    _paint->SetWidth(_epd->width);
    _paint->SetHeight(_epd->height);
}

const void ScreenDriver::drawList(std::vector<ListEntry> *entries, unsigned long currentCursorPosition)
{
    long currentPage = currentCursorPosition / MAX_NB_LINES;
    int currentRow = 0;

    _paint->Clear(COLORED);
    int i = 0;
    for (auto &entry : *entries)
    {
        if (i >= (currentPage * MAX_NB_LINES))
        {
            if (currentRow < MAX_NB_LINES)
            {
                _paint->DrawStringAt(CHAR_WIDTH, CHAR_HEIGHT/2 + (currentRow * CHAR_HEIGHT), entry.getName()->c_str(), FONT, UNCOLORED);
                ++currentRow;
            }
        }
        ++i;
    }
}

const void ScreenDriver::drawCursor(unsigned long currentSelection)
{
    int currentRow = static_cast<int>(currentSelection % MAX_NB_LINES);
    _paint->DrawFilledRectangle(0, 0, CHAR_WIDTH, SCREEN_HEIGHT, COLORED);
    _paint->DrawStringAt(0, static_cast<int>(CHAR_HEIGHT/2 + (currentRow * CHAR_HEIGHT)), ">", FONT, UNCOLORED);
}

void ScreenDriver::displayPartialFrame(int x, int y, int width, int height)
{
    _epd->SetFrameMemory(_paint->GetImage(), x, y, width, height);
    _epd->DisplayFrame();
}

void ScreenDriver::drawPlayer(MusicFile *musicFile)
{
    _paint->Clear(COLORED);
    _paint->DrawStringAt(0, 10, musicFile->getArtist()->c_str(), &Font20, UNCOLORED);
    _paint->DrawStringAt(0, 30, musicFile->getAlbum()->c_str(), &Font20, UNCOLORED);
    _paint->DrawStringAt(0, 50, musicFile->getTitle()->c_str(), &Font20, UNCOLORED);
    _paint->DrawStringAt(0, 70, std::to_string(musicFile->getBitrate()).c_str(), &Font20, UNCOLORED);
    const char *musicExtension;
    switch (musicFile->getMusicExtension())
    {
        case FLAC:
            musicExtension = std::string("FLAC").c_str();
            break;
        case MP3:
            musicExtension = std::string("MP3").c_str();
            break;
        default:
            musicExtension = std::string("OTHER").c_str();
            break;
    }
    _paint->DrawStringAt(0, 90, musicExtension, &Font20, UNCOLORED);
    _paint->DrawFilledRectangle(20, 110, 120, 130, UNCOLORED);
    _paint->DrawFilledRectangle(21, 111, 119, 129, COLORED);
}

void ScreenDriver::displayFrame()
{
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    _epd->DisplayFrame();
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    _epd->DisplayFrame();
}

void ScreenDriver::quickClear()
{
    _paint->Clear(COLORED);
}
