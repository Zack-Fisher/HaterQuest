#ifndef PREFAB_H
#define PREFAB_H
// exposure point for the prefab system
// also defines some macros for the prefab system

#include "ecs.h"
#include "type.h"

// CHARACTERS
Entity pPlayer(World* world, u8 px, u8 py);
Entity pGuy(World* world, u8 px, u8 py);

// UI
Entity pHello(World* world, u8 px, u8 py);
Entity pSign(World* world, u8 px, u8 py, char* text);

#endif // PREFAB_H
