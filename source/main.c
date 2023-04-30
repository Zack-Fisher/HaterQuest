// util/lib
#include <stdio.h>
#include <stdbool.h>

#include <unistd.h>
#include <time.h>
// components/systems
// UI COMPONENTS
#include "ui/button.h"
#include "ui/label.h"
// WORLD COMPONENTS
#include "mover.h"
#include "ui.h"

#include "file.h"

#include "systems.h"
#include "prefab.h"

#include "layer/draw.h"
#include "layer/prints.h"

// helper defines
#include "color.h"
#include "prints.h"
#include "array.h"

// basic defines, screen size, etc
#include "main.h"
#include "loop.h"

int main(int argc, char** argv) {
    World* initECS() {
        World world;
        init_world(&world);

        pHello(&world, 10, 10);

        return &world;
    }

    World* world = initECS();

    loop_init();

    float deltaTime = 0.05f;

    int x = SCREEN_WIDTH / 2;
    int y = SCREEN_HEIGHT / 2;

    struct timespec last_frame_time;
    clock_gettime(CLOCK_MONOTONIC, &last_frame_time);

    // get the current time in nanoseconds
    u64 last_frame_time = svcGetSystemTick();

    while (true) {
        void updateDelta() 
        {
            // get the current time in nanoseconds
            u64 current_time = svcGetSystemTick();

            // calculate delta time in seconds
            deltaTime = (current_time - last_frame_time) / 1000000000.0f;
            last_frame_time = current_time;
        }
        void refreshLoop(World* world) {
            consoleClear();
            fillScreen(RGBA8(0x20, 0x98, 0x10, 0xFF));
        }

        refreshLoop(world);
        updateDelta();
        loopECS(world, deltaTime);

        loop_main();
    }

    loop_cleanup();

    return 0;
}