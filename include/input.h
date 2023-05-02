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

void input_init();
void input_update();
int** get_action_key_map();
bool is_down(Action a);
bool is_released(Action a);
bool is_pressed(Action a);

#endif // INPUT_H
