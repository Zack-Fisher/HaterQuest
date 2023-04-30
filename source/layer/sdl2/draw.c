#include "draw.h"
#include "renderer.h"
#include <SDL2/SDL.h>

// fill the screen up, based on the screensize.
void fillScreen(u32 color) 
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Set the draw color to red
    SDL_RenderClear(renderer); // Clear the screen with the draw color
    SDL_RenderPresent(renderer); // Present the renderer's content on the window
}