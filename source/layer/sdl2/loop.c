#include <SDL2/SDL.h>
#include <stdio.h>
#include "loop.h"
#include "renderer.h"

void loop_init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not be initialized. SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    ctx->window = SDL_CreateWindow("Fill Screen with Color", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        printf("Window could not be created. SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
    ctx->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("Renderer could not be created. SDL_Error: %s\n", SDL_GetError());
        return 1;
    }
}

void loop_main()
{
    SDL_RenderClear(ctx->renderer);
    SDL_RenderPresent(ctx->renderer);
}

void loop_cleanup()
{
    SDL_DestroyRenderer(ctx->renderer);
    SDL_DestroyWindow(ctx->window);
    SDL_Quit();
}