#include "draw.h"
#include "nc_util.h"

// fill the screen up, based on the screensize.
void fillScreen(u32 color) 
{
    int color_pair_id = rgba_to_color_pair(color);

    // Set background color
    bkgd(COLOR_PAIR(color_pair_id));
    attron(COLOR_PAIR(color_pair_id));

    // Fill the limited screen space with spaces
    for (int y = 0; y < SCREEN_TILE_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_TILE_WIDTH; x++) {
            mvaddch(y, x, ' ');
        }
    }

    attroff(COLOR_PAIR(color_pair_id));
}