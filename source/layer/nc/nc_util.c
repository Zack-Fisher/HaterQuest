#include "nc_util.h"

int rgba_to_color_pair(u32 rgba) {
    static int next_color_pair_id = 1;
    int r = (rgba >> 24) & 0xFF;
    int g = (rgba >> 16) & 0xFF;
    int b = (rgba >> 8) & 0xFF;

    short color_id = next_color_pair_id++;
    init_color(color_id, (short)(r * 1000 / 255), (short)(g * 1000 / 255), (short)(b * 1000 / 255));
    init_pair(color_id, -1, color_id);

    return color_id;
}
