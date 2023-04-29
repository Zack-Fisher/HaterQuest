#ifndef MOVER_H
#define MOVER_H

#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "../ecs.h"

typedef struct {
    u8 x, y;
} Position;

typedef struct {
    u8 x, y;
} Velocity;

typedef struct {
    char symbol;
    u32 color;
} Mover;

SYSTEM_H(move_system)
SYSTEM_H(draw_char_system)

#endif // MOVER_H