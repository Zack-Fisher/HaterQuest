#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include <3ds.h>

typedef struct {
    int x, y, width, height;
    u32 bgColor, fgColor;
    float progress;
} ProgressBar;

void initProgressBar(ProgressBar *pb, int x, int y, int width, int height, u32 bgColor, u32 fgColor);
void setProgress(ProgressBar *pb, float progress);
void drawProgressBar(ProgressBar *pb, gfxScreen_t screen, gfx3dSide_t side);

#endif // PROGRESSBAR_H
