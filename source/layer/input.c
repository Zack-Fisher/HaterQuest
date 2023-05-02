#include "input.h"

bool key_states[KEY_COUNT] = { false };

static bool current_key_state[KEY_COUNT];
static bool previous_key_state[KEY_COUNT];

void input_init() {
    memset(current_key_state, 0, sizeof(current_key_state));
    memset(previous_key_state, 0, sizeof(previous_key_state));
}

//only the definitions of the action mapping should be dependent on the platform.
bool is_down(Action action) {
    int keycode = get_action_key_map()[action];
    if (keycode < KEY_COUNT) {
        return current_key_state[keycode];
    }
    return false;
}

bool is_released(Action action) {
    int keycode = get_action_key_map()[action];
    if (keycode < KEY_COUNT) {
        return !current_key_state[keycode] && previous_key_state[keycode];
    }
    return false;
}

bool is_pressed(Action action) {
    int keycode = get_action_key_map()[action];
    if (keycode < KEY_COUNT) {
        return current_key_state[keycode] && !previous_key_state[keycode];
    }
    return false;
}
