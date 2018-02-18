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
    _frame_buffer = (unsigned char*)malloc(_epd->width / 8 * _epd->height);
    memset(_frame_buffer, COLORED, _epd->width / 8 * _epd->height);
    _epd->SetFrameMemory(_frame_buffer, 0, 0, _epd->width, _epd->height);
    _epd->DisplayFrame();
    _epd->SetFrameMemory(_frame_buffer, 0, 0, _epd->width, _epd->height);
    _epd->DisplayFrame();

}

const void ScreenDriver::displayText(std::string *text)
{
    _paint->SetWidth(30);
    _paint->SetHeight(255);
    _paint->Clear(COLORED);
    _paint->DrawStringAt(0, 0, text->c_str(), &Font24, UNCOLORED);
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    _epd->DisplayFrame();
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    _epd->DisplayFrame();
    _paint->SetWidth(_epd->width);
    _paint->SetHeight(_epd->height);
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
    int currentPage = static_cast<int>(currentCursorPosition / MAX_NB_LINES);
    int currentRow = 0;

    /*
     * si le curseur est entre 0 et le MAX_NB_LINES, afficher simplement la première page. Sinon, passer à la Ne page
     */

    std::cout << "max_nb_lines:" << MAX_NB_LINES << std::endl;
    _paint->Clear(COLORED);
    int i = 0;
    for (auto &entry : *entries)
    {
        if (i >= (currentPage * MAX_NB_LINES))
        {
            if (currentRow < MAX_NB_LINES)
            {
                std::cout << "drawing" << entry.getName() << " at " << currentRow << std::endl;
                _paint->DrawStringAt(CHAR_WIDTH, CHAR_HEIGHT/2 + (currentRow * CHAR_HEIGHT), entry.getName(), FONT, UNCOLORED);
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

const void ScreenDriver::displayCursor(unsigned long currentSelection, unsigned long nbSelections)
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
