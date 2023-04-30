#include "controller.h"
#include "layer/input.h"

SYSTEM(
    controller_system,
    // we CANNOT put these in a seperate scope, because we need to access variables from the expansion
    GET_COMPONENT(c, Controller)
    GET_COMPONENT(p, Position),
    {
        if (kDown & KEY_A || kHeld & KEY_A) {
            p->x += c->speed;
        }
        if (kDown & KEY_B || kHeld & KEY_B) {
            p->x -= c->speed;
        }
        if (kDown & KEY_X || kHeld & KEY_X) {
            p->y += c->speed;
        }
        if (kDown & KEY_Y || kHeld & KEY_Y) {
            p->y -= c->speed;
        }
    },
    // Scan input
    hidScanInput();

    // Get the current input state
    u32 kDown = hidKeysDown();
    u32 kHeld = hidKeysHeld();
)