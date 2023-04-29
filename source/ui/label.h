#ifndef LABEL_H
#define LABEL_H

#include <3ds.h>
#include "../mover.h"

#define LABEL_TEXT_MAX 256

typedef struct {
    char text[LABEL_TEXT_MAX];
    gfxScreen_t screen;
    gfx3dSide_t side;
} Label;

SYSTEM_H(draw_label_system)

#endif // LABEL_H
