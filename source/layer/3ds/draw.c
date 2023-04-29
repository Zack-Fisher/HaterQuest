#include "draw.h"

#include <3ds.h>

// fill the screen up, based on the screensize.
void fillScreen(u32 color) 
{
    u32* frameBuffer = (u32*)gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
    for (int y = 0; y < SCREEN_TILE_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_TILE_WIDTH; x++) {
            // Fill the screen with a space character (ASCII code 32) in the specified color
            frameBuffer[y * SCREEN_TILE_WIDTH + x] = (color & 0xFFFFFF00) | 32;
        }
    }
}