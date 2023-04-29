#include "label.h"
#include <stdio.h>

#include "../mover.h"

SYSTEM(
    draw_label_system,
    GET_COMPONENT(l, Label)
    GET_COMPONENT(p, Position),
    {
        printf("\x1b[%d;%dH%s", p->y, p->x, l->text);
    },
)
