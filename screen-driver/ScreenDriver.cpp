#include <iostream>
#include <cstring>
#include "ScreenDriver.h"

ScreenDriver::ScreenDriver()
{
    _epd = new Epd();

//    if (_epd->Init(lut_full_update) != 0)
//    {
//        printf("e-Paper init failed\n");
//        return;
//    }
//    fullClear();
//    _epd->DelayMs(500);
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

const void ScreenDriver::displaySomething()
{
    Paint paint(_frame_buffer, _epd->width, _epd->height);
    paint.Clear(UNCOLORED);
    paint.SetRotate(ROTATE_90);

    /* For simplicity, the arguments are explicit numerical coordinates */
    /* Write strings to the buffer */
    paint.DrawFilledRectangle(0, 10, 128, 30, COLORED);
    paint.DrawStringAt(30, 14, "Hello world!", &Font12, UNCOLORED);
    paint.DrawStringAt(30, 34, "e-Paper Demo", &Font12, COLORED);
    _epd->SetFrameMemory(paint.GetImage(), 0, 0, paint.GetWidth(), paint.GetHeight());
    _epd->DisplayFrame();

    /* Draw something to the frame_buffer
    paint.DrawRectangle(10, 60, 50, 100, COLORED);
    paint.DrawLine(10, 60, 50, 100, COLORED);
    paint.DrawLine(50, 60, 10, 100, COLORED);
    paint.DrawCircle(88, 80, 30, COLORED);
    paint.DrawFilledRectangle(10, 120, 50, 180, COLORED);
    paint.DrawFilledCircle(88, 150, 30, COLORED);*/

    /* Display the frame_buffer */
/*    _epd->DelayMs(2000);

    if (_epd->Init(lut_partial_update) != 0) {
        printf("e-Paper init failed\n");
        return;
    }*/

    /**
     *  there are 2 memory areas embedded in the e-paper display
     *  and once the display is refreshed, the memory area will be auto-toggled,
     *  i.e. the next action of SetFrameMemory will set the other memory area
     *  therefore you have to set the frame memory and refresh the display twice.
     */
/*
    epd.SetFrameMemory(IMAGE_DATA, 0, 0, epd.width, epd.height);
    epd.DisplayFrame();
    epd.SetFrameMemory(IMAGE_DATA, 0, 0, epd.width, epd.height);
    epd.DisplayFrame();
*/
    char time_string[] = {'0', '0', ':', '0', '0', '\0'};
    /*while (1) {
        time(&now);
        timenow = localtime(&now);
        time_string[0] = timenow->tm_min / 10 + '0';
        time_string[1] = timenow->tm_min % 10 + '0';
        time_string[3] = timenow->tm_sec / 10 + '0';
        time_string[4] = timenow->tm_sec % 10 + '0';

        paint.SetWidth(32);
        paint.SetHeight(96);
        paint.Clear(UNCOLORED);
        paint.DrawStringAt(8, 4, time_string, &Font24, COLORED);

        epd.SetFrameMemory(paint.GetImage(), 80, 72, paint.GetWidth(), paint.GetHeight());
        epd.DisplayFrame();
        epd.DelayMs(500);
    }*/
}

const void ScreenDriver::fullClear()
{
    _frame_buffer = (unsigned char*)malloc(_epd->width / 8 * _epd->height);
    memset(_frame_buffer, UNCOLORED, _epd->width / 8 * _epd->height);
    _epd->SetFrameMemory(_frame_buffer, 0, 0, _epd->width, _epd->height);
    _epd->DisplayFrame();
    _epd->SetFrameMemory(_frame_buffer, 0, 0, _epd->width, _epd->height);
    _epd->DisplayFrame();

}

const void ScreenDriver::displayText(std::string *text)
{
    _paint->SetWidth(30);
    _paint->SetHeight(255);
    _paint->Clear(UNCOLORED);
    _paint->DrawStringAt(0, 0, text->c_str(), &Font24, COLORED);
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    _epd->DisplayFrame();
}

const void ScreenDriver::displayBootScreen()
{
    _paint->SetWidth(128);
    _paint->SetHeight(255);
    _paint->Clear(COLORED);
    _paint->DrawStringAt(90, 52, "PiPod", &Font24, UNCOLORED);
    _epd->SetFrameMemory(_paint->GetImage(), 0, 0, _paint->GetWidth(), _paint->GetHeight());
    _epd->DisplayFrame();
}