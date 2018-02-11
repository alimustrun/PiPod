#include "ScreenDriver.h"

const void ScreenDriver::displaySomething()
{
    time_t now;
    struct tm* timenow;

    Epd epd;
    if (epd.Init(lut_full_update) != 0)
    {
        printf("e-Paper init failed\n");
        return;
    }

    unsigned char* frame_buffer = (unsigned char*)malloc(epd.width / 8 * epd.height);

    Paint paint(frame_buffer, epd.width, epd.height);
    paint.Clear(UNCOLORED);

    /* For simplicity, the arguments are explicit numerical coordinates */
    /* Write strings to the buffer */
    paint.DrawFilledRectangle(0, 10, 128, 30, COLORED);
    paint.DrawStringAt(30, 14, "Hello world!", &Font12, UNCOLORED);
    paint.DrawStringAt(30, 34, "e-Paper Demo", &Font12, COLORED);

    /* Draw something to the frame_buffer */
    paint.DrawRectangle(10, 60, 50, 100, COLORED);
    paint.DrawLine(10, 60, 50, 100, COLORED);
    paint.DrawLine(50, 60, 10, 100, COLORED);
    paint.DrawCircle(88, 80, 30, COLORED);
    paint.DrawFilledRectangle(10, 120, 50, 180, COLORED);
    paint.DrawFilledCircle(88, 150, 30, COLORED);

    /* Display the frame_buffer */
    epd.SetFrameMemory(paint.GetImage(), 0, 0, paint.GetWidth(), paint.GetHeight());
    epd.DisplayFrame();
    epd.DelayMs(2000);

    if (epd.Init(lut_partial_update) != 0) {
        printf("e-Paper init failed\n");
        return;
    }

    /**
     *  there are 2 memory areas embedded in the e-paper display
     *  and once the display is refreshed, the memory area will be auto-toggled,
     *  i.e. the next action of SetFrameMemory will set the other memory area
     *  therefore you have to set the frame memory and refresh the display twice.
     */
    epd.SetFrameMemory(IMAGE_DATA, 0, 0, epd.width, epd.height);
    epd.DisplayFrame();
    epd.SetFrameMemory(IMAGE_DATA, 0, 0, epd.width, epd.height);
    epd.DisplayFrame();

    char time_string[] = {'0', '0', ':', '0', '0', '\0'};
    while (1) {
        time(&now);
        timenow = localtime(&now);
        time_string[0] = timenow->tm_min / 10 + '0';
        time_string[1] = timenow->tm_min % 10 + '0';
        time_string[3] = timenow->tm_sec / 10 + '0';
        time_string[4] = timenow->tm_sec % 10 + '0';

        paint.SetWidth(32);
        paint.SetHeight(96);
        paint.SetRotate(ROTATE_90);
        paint.Clear(UNCOLORED);
        paint.DrawStringAt(8, 4, time_string, &Font24, COLORED);

        epd.SetFrameMemory(paint.GetImage(), 80, 72, paint.GetWidth(), paint.GetHeight());
        epd.DisplayFrame();
        epd.DelayMs(500);
    }
}


