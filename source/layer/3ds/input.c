#include "input.h"
#include <3ds.h>

static int** action_key_map {
    KEY_DUP,
    KEY_DDOWN,
    KEY_DLEFT,
    KEY_DRIGHT,
    KEY_A
};

void input_update()
{
    memcpy(previous_key_state, current_key_state, sizeof(current_key_state));

    hidScanInput();
    u32 kDown = hidKeysDown();
    u32 kHeld = hidKeysHeld();
    
    current_key_state[KEY_UP] = (kDown & KEY_DUP) || (kHeld & KEY_DUP);
    current_key_state[KEY_DOWN] = (kDown & KEY_DDOWN) || (kHeld & KEY_DDOWN);
    current_key_state[KEY_LEFT] = (kDown & KEY_DLEFT) || (kHeld & KEY_DLEFT);
    current_key_state[KEY_RIGHT] = (kDown & KEY_DRIGHT) || (kHeld & KEY_DRIGHT);
    current_key_state[KEY_QUIT] = (kDown & KEY_START) || (kHeld & KEY_START);
}

int** get_action_key_map()
{
    return action_key_map;
}