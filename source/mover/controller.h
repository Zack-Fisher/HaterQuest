#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <ctype.h>
#include <3ds.h>

#include "pos.h"

typedef struct {
    u32 speed;
} Controller;

SYSTEM_H(controller_system)

#endif // CONTROLLER_H