#include "systems.h"

#include "mover.h"
#include "ui.h"

// define our pipeline and split into sections here.
void loopECS(World* world, float deltaTime) {
    // CALL(controller);
    // CALL(mover);
    CALL(ui);
}


void mover(World* world, float deltaTime) {
    CALL(move_system);
    CALL(draw_char_system);
}

void controller(World* world, float deltaTime) {
    CALL(controller_system);
}

void ui(World* world, float deltaTime) {
    CALL(draw_label_system);
}
