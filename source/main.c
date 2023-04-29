// util/lib
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <3ds.h>

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

// helper defines
#include "color.h"
#include "prints.h"
#include "array.h"

// basic defines, screen size, etc
#include "main.h"

void drawBackground(u32 color) {
    u32* frameBuffer = (u32*)gfxGetFramebuffer(GFX_TOP, GFX_LEFT, NULL, NULL);
    for (int y = 0; y < 240; y++) {
        for (int x = 0; x < 400; x++) {
            frameBuffer[y * 400 + x] = color;
        }
    }
}

int main(int argc, char** argv) {
    World* initECS() {
        World world;
        init_world(&world);

        pHello(&world, 10, 10);

        return &world;
    }

    gfxInitDefault();
    consoleInit(GFX_TOP, NULL);

    World* world = initECS();

    float deltaTime = 0.05f;

    int x = SCREEN_WIDTH / 2;
    int y = SCREEN_HEIGHT / 2;

    // get the current time in nanoseconds
    u64 last_frame_time = svcGetSystemTick();

    while (aptMainLoop()) {
        void updateDelta() 
        {
            // get the current time in nanoseconds
            u64 current_time = svcGetSystemTick();

            // calculate delta time in seconds
            deltaTime = (current_time - last_frame_time) / 1000000000.0f;
        }
        void refreshLoop(World* world) {
            consoleClear();
            drawBackground(RGBA8(0x20, 0x98, 0x10, 0xFF));
        }
        void testLoop(World* world) {
            for (int i = 1; i < 6; ++i)
            {
                printf("\x1b[%d;%dHhappy birthday %d\n", i, i, i);
            }
        }

        refreshLoop(world);
        updateDelta();
        testLoop(world);
        loopECS(world, deltaTime);

        gfxFlushBuffers();
        gfxSwapBuffers();

        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}