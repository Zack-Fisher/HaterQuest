#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>
#include <string.h>

// check for pressed on actions themselves, not keys
typedef enum {
    ACTION_UP,
    ACTION_DOWN,
    ACTION_LEFT,
    ACTION_RIGHT,
    ACTION_INTERACT,
    ACTION_COUNT
} Action;

// define different mappings for different platforms
#ifdef _3ds
    int action_key_map[ACTION_COUNT] = {
        KEY_DUP,
        KEY_DDOWN,
        KEY_DLEFT,
        KEY_DRIGHT
    };
#elif defined(__linux__)
#include <ncurses.h>
    int action_key_map[ACTION_COUNT] = {
        KEY_UP,
        KEY_DOWN,
        KEY_LEFT,
        KEY_RIGHT
    };
#endif

void input_init();
void input_update();
bool is_down(Action a);
bool is_released(Action a);
bool is_pressed(Action a);

#endif // INPUT_H
