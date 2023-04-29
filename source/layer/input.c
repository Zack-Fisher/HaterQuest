#include "input.h"

#ifdef _3DS
    #include <3ds.h>
#elif defined(__linux__)
    #include <ncurses.h>
#else
    #error "Unsupported platform"
#endif

bool key_states[KEY_COUNT] = { false };

static bool current_key_state[KEY_COUNT];
static bool previous_key_state[KEY_COUNT];

void input_init() {
    memset(current_key_state, 0, sizeof(current_key_state));
    memset(previous_key_state, 0, sizeof(previous_key_state));
}

void input_update() {
    memcpy(previous_key_state, current_key_state, sizeof(current_key_state));

    #ifdef _3DS
        hidScanInput();
        u32 kDown = hidKeysDown();
        u32 kHeld = hidKeysHeld();
        
        current_key_state[KEY_UP] = (kDown & KEY_DUP) || (kHeld & KEY_DUP);
        current_key_state[KEY_DOWN] = (kDown & KEY_DDOWN) || (kHeld & KEY_DDOWN);
        current_key_state[KEY_LEFT] = (kDown & KEY_DLEFT) || (kHeld & KEY_DLEFT);
        current_key_state[KEY_RIGHT] = (kDown & KEY_DRIGHT) || (kHeld & KEY_DRIGHT);
        current_key_state[KEY_QUIT] = (kDown & KEY_START) || (kHeld & KEY_START);
    #elif defined(__linux__)
        int ch = getch();
        switch (ch) {
            case KEY_UP:
                current_key_state[KEY_UP] = true;
                break;
            case KEY_DOWN:
                current_key_state[KEY_DOWN] = true;
                break;
            case KEY_LEFT:
                current_key_state[KEY_LEFT] = true;
                break;
            case KEY_RIGHT:
                current_key_state[KEY_RIGHT] = true;
                break;
            case 'q':
            case 'Q':
                current_key_state[KEY_QUIT] = true;
                break;
            default:
                current_key_state[KEY_UP] = false;
                current_key_state[KEY_DOWN] = false;
                current_key_state[KEY_LEFT] = false;
                current_key_state[KEY_RIGHT] = false;
                current_key_state[KEY_QUIT] = false;
                break;
        }
    #endif
}

bool is_down(Key keycode) {
    if (keycode < KEY_COUNT) {
        return current_key_state[keycode];
    }
    return false;
}

bool is_released(Key keycode) {
    if (keycode < KEY_COUNT) {
        return !current_key_state[keycode] && previous_key_state[keycode];
    }
    return false;
}

bool is_pressed(Key keycode) {
    if (keycode < KEY_COUNT) {
        return current_key_state[keycode] && !previous_key_state[keycode];
    }
    return false;
}
