#include "label.h"
#include <stdio.h>

#include "../mover.h"
#include "layer/prints.h"

SYSTEM(
    draw_label_system,
    GET_COMPONENT(l, Label)
    GET_COMPONENT(p, Position),
    {
        fprint(p->x, p->y, "%s", l->text);
    },
)
