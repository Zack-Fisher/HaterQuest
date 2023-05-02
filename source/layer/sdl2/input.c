#include "input.h"
#include <SDL2/SDL.h>

static int** action_key_map {
    SDL_SCANCODE_UP,
    SDL_SCANCODE_DOWN,
    SDL_SCANCODE_LEFT,
    SDL_SCANCODE_RIGHT,
    SDL_SCANCODE_SPACE
};

void input_update()
{

}


int** get_action_key_map()
{
    return action_key_map;
}

