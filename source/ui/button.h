#pragma once

#include <3ds.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    int x, y, width, height;
} Button;

int isButtonPressed(Button *button, touchPosition touch);

void button_system(Button *button);