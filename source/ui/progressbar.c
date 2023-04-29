#include "progressbar.h"

void initProgressBar(ProgressBar *pb, int x, int y, int width, int height, u32 bgColor, u32 fgColor) {
    pb->x = x;
    pb->y = y;
    pb->width = width;
    pb->height = height;
    pb->bgColor = bgColor;
    pb->fgColor = fgColor;
    pb->progress = 0.0f;
}

void setProgress(ProgressBar *pb, float progress) {
    if (progress < 0.0f) progress = 0.0f;
    if (progress > 100.0f) progress = 100.0f;
    pb->progress = progress;
}

void drawProgressBar(ProgressBar *pb, gfxScreen_t screen, gfx3dSide_t side) {
    u32* frameBuffer = (u32*)gfxGetFramebuffer(screen, side, NULL, NULL);
    int screenWidth = screen == GFX_TOP ? 400 : 320;
    int filledWidth = (int)(pb->width * pb->progress / 100.0f);

    for (int y = pb->y; y < pb->y + pb->height; y++) {
        for (int x = pb->x; x < pb->x + pb->width; x++) {
            if (x < pb->x + filledWidth) {
                frameBuffer[y * screenWidth + x] = pb->fgColor;
            } else {
                frameBuffer[y * screenWidth + x] = pb->bgColor;
            }
        }
    }
}