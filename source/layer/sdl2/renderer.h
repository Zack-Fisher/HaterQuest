#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct {
    SDL_Window* window;
    SDL_Renderer* renderer;
} SDL_Ctx;

SDL_Ctx* ctx; 
