#include <iostream>
#include <cstring>
#include "ScreenDriver.h"

ScreenDriver::ScreenDriver()
{
    _epd = new Epd();
    if (_epd->Init(lut_partial_update) != 0)
    {
        printf("e-Paper init failed\n");
        return;
    }
    fullClear();
    _frame_buffer = (unsigned char*)malloc(_epd->width / 8 * _epd->height);
    _paint = new Paint(_frame_buffer, _epd->width, _epd->height);
    _paint->SetRotate(ROTATE_90);
}

const void ScreenDriver::fullClear()
{
    std::cout << "0" << std::endl;
    _paint = new Paint(_frame_buffer, _epd->width, _epd->height);
    std::cout << "1" << std::endl;
    _paint->SetWidth(_epd->width);
    std::cout << "2" << std::endl;
    _paint->SetHeight(_epd->height);
    std::cout << "3" << std::endl;
    _paint->Clear(UNCOLORED);
    std::cout << "4" << std::endl;
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    std::cout << "5" << std::endl;
    _epd->DisplayFrame();
    std::cout << "6" << std::endl;
    _paint->Clear(COLORED);
    std::cout << "7" << std::endl;
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    std::cout << "8" << std::endl;
    _epd->DisplayFrame();
    std::cout << "9" << std::endl;
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    std::cout << "10" << std::endl;
    _epd->DisplayFrame();
    std::cout << "11" << std::endl;
}

const void ScreenDriver::displayBootScreen()
{
    _paint->SetWidth(30);
    _paint->SetHeight(255);
    _paint->Clear(COLORED);
    _paint->DrawStringAt(0, 0, "PiPod", &Font24, UNCOLORED);
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    _epd->DisplayFrame();
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    _epd->DisplayFrame();
    _paint->SetWidth(_epd->width);
    _paint->SetHeight(_epd->height);
}

const void ScreenDriver::displayList(std::vector<ListEntry> *entries, unsigned long currentCursorPosition)
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
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    _epd->DisplayFrame();
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    _epd->DisplayFrame();
}

const void ScreenDriver::displayCursor(unsigned long currentSelection)
{
    int currentRow = static_cast<int>(currentSelection % MAX_NB_LINES);

    _paint->SetWidth(SCREEN_HEIGHT);
    _paint->SetHeight(CHAR_WIDTH);
    _paint->Clear(COLORED);
    _paint->DrawStringAt(0, static_cast<int>(CHAR_HEIGHT/2 + (currentRow * CHAR_HEIGHT)), ">", FONT, UNCOLORED);
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    _epd->DisplayFrame();
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    _epd->DisplayFrame();
    _paint->SetWidth(_epd->width);
    _paint->SetHeight(_epd->height);
}
