#include <math.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>

#include "SDL2/SDL_events.h"
#include "SDL2/SDL_mouse.h"
#include "SDL2/SDL_render.h"
#include "SDL2/SDL_timer.h"
#include "common.h"
#include "turtle.h"

SDL_Window      *window;
SDL_Renderer    *renderer;

ATTRIBUTE(constructor)
void init(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Turtle Lab", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

int main(int argc, char *argv[])
{
    struct turtle *turtle = create_turtle(window, renderer);

    SDL_RenderClear(renderer);
    turtle_forward(turtle, 100);

    bool exit;
    while (!exit) {
        ON_EVENT(SDL_QUIT) {
            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Goodbyeee!", "Cya later!", window);

            exit = true;
            break;
        }

        ON_EVENT(SDL_MOUSEBUTTONDOWN) {

            point_t mouse_pos;

            SDL_GetMouseState(&mouse_pos.x, &mouse_pos.y);

            turtle_forward(turtle, ceil(mouse_pos.x / 10));
            
        }
    }

    free(turtle);
}

ATTRIBUTE(destructor)
void destructor(void)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
