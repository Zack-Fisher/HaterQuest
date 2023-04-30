#include "button.h"
#include "../color.h"

int isButtonPressed(Button *button, touchPosition touch) {
    return touch.px >= button->x && touch.px <= button->x + button->width && touch.py >= button->y && touch.py <= button->y + button->height;
}

void button_system(Button *button) {
    touchPosition touch; hidTouchRead(&touch);
    if (isButtonPressed(button, touch)) {
    }
}
