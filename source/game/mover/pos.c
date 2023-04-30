#include "pos.h"

SYSTEM(
    // name the system
    move_system,
    // then grab the components
    GET_COMPONENT(p, Position)
    GET_COMPONENT(v, Velocity),
    // then operate on the system. null checks are automatically handled in the macro.
    {
        p->x += v->x * delta_time;
        p->y += v->y * delta_time;
    },
)

SYSTEM(
    draw_char_system,
    GET_COMPONENT(p, Position)
    GET_COMPONENT(m, Mover),
    {
        u32* frameBuffer = (u32*)gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
        frameBuffer[p->y * 400 + p->x] = m->color;
    },
)