// util/lib
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>

#ifdef _3DS
    #include <3ds.h>
#elif defined(__linux__)
    #include <ncurses.h>
    #include <unistd.h>
    #include <time.h>
#else
    #error "Unsupported platform"
#endif
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

void drawBackground(u32 color) {
}

int main(int argc, char** argv) {
    World* initECS() {
        World world;
        init_world(&world);

        pHello(&world, 10, 10);

        return &world;
    }

    // Initialize platform-specific graphics and input
    #ifdef _3DS
        gfxInitDefault();
        consoleInit(GFX_TOP, NULL);
    #elif defined(__linux__)
        initscr();
        raw();
        keypad(stdscr, TRUE);
        noecho();
        curs_set(0);
        start_color();
    #endif

    World* world = initECS();

    float deltaTime = 0.05f;

    int x = SCREEN_WIDTH / 2;
    int y = SCREEN_HEIGHT / 2;

    // get the current time in nanoseconds
    #ifdef _3DS
        u64 last_frame_time = svcGetSystemTick();
    #elif defined(__linux__)
        struct timespec last_frame_time;
        clock_gettime(CLOCK_MONOTONIC, &last_frame_time);
    #endif

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
        void testLoop(World* world) {
            for (int i = 1; i < 6; ++i)
            {
                printf("\x1b[%d;%dHhappy birthday %d\n", i, i, i);
            }
        }

        #ifdef _3DS
            if (!aptMainLoop()) break;
        #elif defined(__linux__)
            int ch = getch();
            if (ch == 'q' || ch == 'Q') break;  // Quit on 'q' or 'Q' key press
        #endif

        refreshLoop(world);
        updateDelta();
        testLoop(world);
        loopECS(world, deltaTime);

        #ifdef _3DS
            gfxFlushBuffers();
            gfxSwapBuffers();
            gspWaitForVBlank();
        #elif defined(__linux__)
            refresh();
            usleep(1000000 / 60);  // Sleep for approximately 1/60th of a second
        #endif
    }

    // Deinitialize platform-specific graphics and input
    #ifdef _3DS
        gfxExit();
    #elif defined(__linux__)
        endwin();
    #endif

    return 0;
}

    while (aptMainLoop()) {


        gfxFlushBuffers();
        gfxSwapBuffers();

        gspWaitForVBlank();
    }

    gfxExit();
    return 0;
}